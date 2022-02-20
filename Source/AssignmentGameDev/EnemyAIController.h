// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAMEDEV_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY()
		TArray<AActor*> Waypoints;
	UFUNCTION()
		AActor* ChooseWaypoint();
	UFUNCTION()
		void RandomPatrol();
	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehTree;
	UFUNCTION()
		void Tick(float DeltaTime);
	/*UFUNCTION()
		bool isSeen(APawn* PlayerPawn);*/
};
