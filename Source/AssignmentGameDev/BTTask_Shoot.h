// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAMEDEV_API UBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
private:
	UPROPERTY(EditAnywhere)
		USoundBase* FireSound; // Fire sound of AI's gun, can be assigned in the Behavioral Tree
	UPROPERTY(EditAnywhere)
		float EnemyFireDamage = 15.0f; //Damage of the AI, can be changed in the Behavioral Tree
	
};
