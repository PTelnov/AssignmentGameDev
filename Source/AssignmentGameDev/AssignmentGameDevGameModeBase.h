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
	
public:
	UFUNCTION()
		void GameOver(bool win);
private:
	FTimerHandle EndGameTimer;
	UPROPERTY(EditAnywhere)
		float GameDuration = 40.0f; // Duration of the game, if the time runs out the player will lose. Value can be changed in blueprint
	UFUNCTION()
		void TimeUp(); // The function is called when time runs out.
	UFUNCTION()
		void StartGame();
	
	UFUNCTION()
		void BeginPlay();

};
