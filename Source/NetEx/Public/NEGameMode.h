// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NEGameMode.generated.h"


UENUM(BlueprintType)
enum class ETeamC : uint8
{
	red_server,

	blue_client
};



class ANEChar;
class ANEPlayerController;


UCLASS()
class NETEX_API ANEGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ANEGameMode();

protected:
	int server_char_index;
	int client_char_index;

	ANEPlayerController * remote_controller;

	TArray<ANEChar*> server_chars;
	TArray<ANEChar*> client_chars;

	int NextArrayIndex(TArray<ANEChar*> ar, int current_index);

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	void InitChars(TArray<ANEChar*>& ar, ETeamC team);
	ANEChar* GetNextChar(TArray<ANEChar*> ar, int index);

	void ClientCharNext();
	void ServerCharNext();

	void SetupInput();
	
	
};
