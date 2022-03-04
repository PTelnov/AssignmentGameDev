// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_BB_Distance.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"


void UBTService_BB_Distance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* aiCont = OwnerComp.GetAIOwner();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	APawn* AIPawn = aiCont->GetPawn();
	FVector PlayerLoc = PlayerPawn->GetActorLocation(); // Gets player location
	FVector AiLoc = AIPawn->GetActorLocation(); // Gets ai location
	
	
	if (FVector::Dist(PlayerLoc, AiLoc) <= shootingDist) // If AI is in shooting radius, sets a boolean, which states that AI can shoot.
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}

		
	
}

