// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if (BehTree != nullptr) // Checks if Beh Tree is assigned correctly
	{
		RunBehaviorTree(BehTree); //Runs behavioral tree
	}

	

}


void AEnemyAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	
}


void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const
	FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	
}