// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AssignmentGameDevGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAMEDEV_API AAssignmentGameDevGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	FTimerHandle EndGameTimer;
	UPROPERTY(EditAnywhere)
		float GameDuration = 5.0f;
	UFUNCTION()
		void TimeUp();
	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void GameOver(bool win);
	UFUNCTION()
		void BeginPlay();

};
