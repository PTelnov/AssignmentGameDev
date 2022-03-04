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
	FVector PlayerLoc = PlayerPawn->GetActorLocation(); // Gets player location
	FVector AiToPlayer = PlayerLoc - AIPawn->GetActorLocation(); // Gets a vector between player location and ai location
	AiToPlayer.Normalize();
	FVector ForVector = AIPawn->GetActorForwardVector(); // Gets forward vector, which is needed to calculate dot product

	if (aiCont->LineOfSightTo(PlayerPawn) && FVector::DotProduct(AiToPlayer, ForVector) > 0) // Checks if player is in line of sight to AI and then checks if it is infront of the AI
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());//Sets player position if "AI" sees player
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
