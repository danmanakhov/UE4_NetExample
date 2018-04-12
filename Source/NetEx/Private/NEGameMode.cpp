// Fill out your copyright notice in the Description page of Project Settings.

#include "NEGameMode.h"
#include "NEPlayerController.h"
#include "NEChar.h" 




ANEGameMode::ANEGameMode()
{
	server_char_index = -1;
	client_char_index = -1;
}


int ANEGameMode::NextArrayIndex(TArray<ANEChar*> ar, int current_index)
{
	current_index++;

	if (current_index > ar.Num())
		current_index = 0;

	return current_index;
}


void ANEGameMode::BeginPlay()
{
	InitChars(server_chars, ETeamC::red_server);
	InitChars(client_chars, ETeamC::blue_client);

	SetupInput();
}


void ANEGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}



void ANEGameMode::InitChars(TArray<ANEChar*>& ar, ETeamC team)
{
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; It++)
	{
		ANEChar * pawn = Cast<ANEChar>(It->Get());
		
		if (pawn) 
		{
			if (pawn->team == team)
				ar.Add(pawn);
		}
		
	}
}



ANEChar* ANEGameMode::GetNextChar(TArray<ANEChar*> ar, int index)
{
	index = NextArrayIndex(ar, index);
	
	if (ar.IsValidIndex(index))
		return ar[index];
	else
		return NULL;
}


void ANEGameMode::ClientCharNext()
{
	ANEChar* pawn = GetNextChar(client_chars, client_char_index);
}


void ANEGameMode::ServerCharNext()
{
	ANEChar* pawn = GetNextChar(server_chars, server_char_index);


	UWorld * world = GetWorld();

	if (world)
	{
		APlayerController * pc = world->GetFirstPlayerController();

		if (pc)
		{
			pc->Possess(pawn);
		}
	}
}


void ANEGameMode::SetupInput()
{
	UWorld * world = GetWorld();

	if (world)
	{
		APlayerController * pc = world->GetFirstPlayerController();

		if (pc)
		{
			pc->InputComponent->BindAction("server_pawn_next", IE_Pressed, this, &ANEGameMode::ServerCharNext);
			pc->InputComponent->BindAction("client_pawn_next", IE_Pressed, this, &ANEGameMode::ClientCharNext);
		}
	}
}
