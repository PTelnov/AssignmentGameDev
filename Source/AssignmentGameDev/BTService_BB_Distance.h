// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_BB_Distance.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTGAMEDEV_API UBTService_BB_Distance : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	UPROPERTY(EditAnywhere)
		float shootingDist = 100.0f;
};
