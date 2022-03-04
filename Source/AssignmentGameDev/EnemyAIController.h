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
	
	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehTree; // Pointer to the Behavioral tree
	UFUNCTION()
		void Tick(float DeltaTime);
	
};
