// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
class APlayerCharacter;
class UUserWidget;

UCLASS()
class ASSIGNMENTGAMEDEV_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void SetupInputComponent();
	virtual void CallForwards(float Value);
	virtual void CallTurn(float Value);
	virtual void CallPitch(float Value);
	virtual void CallStrafe(float Value);
	virtual void CallFire();
	virtual void CallJump();
	virtual void CallThrow();

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> HPHUDClass; // A template of the hud 
	UPROPERTY()
		UUserWidget* HPCount; // A pointer to the HUD
	UFUNCTION(BlueprintPure)
		int GetHP(); // A function, which can be accessed from the HUD to display current Health



	APlayerCharacter* MyCharacter;
	ACharacter* Character;
};
