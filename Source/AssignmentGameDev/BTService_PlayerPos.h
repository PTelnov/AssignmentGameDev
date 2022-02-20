// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerPos.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAMEDEV_API UBTService_PlayerPos : public UBTService_BlackboardBase
{
	GENERATED_BODY()

private:
	bool isSeen(APawn* PlayerPawn);
protected:
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
