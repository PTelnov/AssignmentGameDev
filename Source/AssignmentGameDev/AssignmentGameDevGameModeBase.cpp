// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kismet/GameplayStatics.h"
#include "AssignmentGameDevGameModeBase.h"




void AAssignmentGameDevGameModeBase::TimeUp()
{
	GameOver(false);
}

void AAssignmentGameDevGameModeBase::StartGame()
{
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &AAssignmentGameDevGameModeBase::TimeUp, GameDuration, false);
}

void AAssignmentGameDevGameModeBase::GameOver(bool win)
{
	UGameplayStatics::OpenLevel(GetWorld(), "EndLevel");
}

void AAssignmentGameDevGameModeBase::BeginPlay()
{
	StartGame();
}
