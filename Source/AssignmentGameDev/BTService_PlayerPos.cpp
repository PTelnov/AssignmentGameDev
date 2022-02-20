// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerPos.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"





void UBTService_PlayerPos::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* aiCont = OwnerComp.GetAIOwner();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	APawn* AIPawn = aiCont->GetPawn();
	FVector PlayerLoc = PlayerPawn->GetActorLocation();
	FVector AiToPlayer = PlayerLoc - AIPawn->GetActorLocation();
	AiToPlayer.Normalize();
	FVector ForVector = AIPawn->GetActorForwardVector();

	if (aiCont->LineOfSightTo(PlayerPawn) && FVector::DotProduct(AiToPlayer, ForVector) > 0)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
