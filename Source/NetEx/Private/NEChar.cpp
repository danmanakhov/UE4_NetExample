// Fill out your copyright notice in the Description page of Project Settings.

#include "NEChar.h"
#include "NEGameMode.h"



// Sets default values
ANEChar::ANEChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	team = ETeamC::red_server;
}

// Called when the game starts or when spawned
void ANEChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANEChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANEChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

