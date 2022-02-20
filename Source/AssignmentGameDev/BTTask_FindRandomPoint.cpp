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
	AActor* Enemy = OwnerComp.GetAIOwner()->GetPawn();

	float RandRadius = 2000.0f;
	FNavLocation RandPoint;

	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	NavSys->GetRandomReachablePointInRadius(Enemy->GetActorLocation(), RandRadius, RandPoint);

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("RandPoint"), RandPoint);

	return EBTNodeResult::Succeeded;
}