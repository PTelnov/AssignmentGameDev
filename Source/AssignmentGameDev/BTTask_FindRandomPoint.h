// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindRandomPoint.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAMEDEV_API UBTTask_FindRandomPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
private:
	UPROPERTY(EditAnywhere)
		float RandRadius = 2000.0f; // Radius in which AI will be looking for random point
	
};
