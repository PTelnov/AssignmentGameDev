// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kismet/GameplayStatics.h"
#include "AssignmentGameDevGameModeBase.h"




void AAssignmentGameDevGameModeBase::TimeUp() // The function, which is called when Timer ends
{
	GameOver(false);
}

void AAssignmentGameDevGameModeBase::StartGame() // At the start of the game the timer will start running
{
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &AAssignmentGameDevGameModeBase::TimeUp, GameDuration, false);
	
}

void AAssignmentGameDevGameModeBase::GameOver(bool win) // Depending on the win or defeat of the player, different screen will be opened 
{
	if (win == true)
	{
		UGameplayStatics::OpenLevel(GetWorld(), "EndLevelWin");
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), "EndLevelLose");
	}
}

void AAssignmentGameDevGameModeBase::BeginPlay()
{
	StartGame();
}
