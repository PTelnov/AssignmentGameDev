// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationSystem.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "BTTask_FindRandomPoint.h"

EBTNodeResult::Type UBTTask_FindRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AActor* Enemy = OwnerComp.GetAIOwner()->GetPawn();// Gets AI's pawn
 
	FNavLocation RandPoint;

	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this); // Gets current Nav mesh
	NavSys->GetRandomReachablePointInRadius(Enemy->GetActorLocation(), RandRadius, RandPoint); // Looks for the random location in the "RandRadius" radius.

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("RandPoint"), RandPoint); // Sets Random Location on the nav mesh to the blackboard

	return EBTNodeResult::Succeeded;
}