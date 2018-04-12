// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NEChar.generated.h"


enum class ETeamC : uint8;


UCLASS()
class NETEX_API ANEChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANEChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ETeamC team;

	
	
};
