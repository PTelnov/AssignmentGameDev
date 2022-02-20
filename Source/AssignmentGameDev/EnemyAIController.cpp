// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	/*SetFocus(PlayerPawn);
	MoveToActor(PlayerPawn, 10.0f);*/
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	if (BehTree != nullptr)
	{
		RunBehaviorTree(BehTree);
	}

	for (AActor* Waypoint : Waypoints)
	{
		UE_LOG(LogTemp, Warning, TEXT("Waypoint check"));
		if (Waypoint->ActorHasTag(TEXT("Lookout")))
		{
			UE_LOG(LogTemp, Warning, TEXT("Waypoint check1"));
			GetBlackboardComponent()->SetValueAsVector(TEXT("Lookout"), Waypoint->GetActorLocation());
		}
	}

	//RandomPatrol();


}

AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Waypoints[index];

}

void AEnemyAIController::RandomPatrol()
{
	MoveToActor(ChooseWaypoint());
}

//bool AEnemyAIController::isSeen(APawn* PlayerPawn)
//{
//
//	APawn* AIPawn = GetPawn();
//	FVector PlayerLoc = PlayerPawn->GetActorLocation();
//	FVector AiToPlayer = PlayerLoc - AIPawn->GetActorLocation();
//	AiToPlayer.Normalize();
//	FVector ForVector = AIPawn->GetActorForwardVector();
//	if (LineOfSightTo(PlayerPawn) && FVector::DotProduct(AiToPlayer, ForVector) > 0)
//	{
//		return true;
//	}
//	return false;
//}

void AEnemyAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	/*APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (LineOfSightTo(PlayerPawn))
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	}
	else
	{
		GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	}*/
}


void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const
	FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	/*RandomPatrol();*/
}