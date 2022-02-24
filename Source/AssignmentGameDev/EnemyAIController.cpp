// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	/*UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);*/

	if (BehTree != nullptr)
	{
		RunBehaviorTree(BehTree);
	}

	/*for (AActor* Waypoint : Waypoints)
	{
		UE_LOG(LogTemp, Warning, TEXT("Waypoint check"));
		if (Waypoint->ActorHasTag(TEXT("Lookout")))
		{
			UE_LOG(LogTemp, Warning, TEXT("Waypoint check1"));
			GetBlackboardComponent()->SetValueAsVector(TEXT("Lookout"), Waypoint->GetActorLocation());
		}
	}*/

	//RandomPatrol();


}

//AActor* AEnemyAIController::ChooseWaypoint()
//{
//	int index = FMath::RandRange(0, Waypoints.Num() - 1);
//	return Waypoints[index];
//
//}




void AEnemyAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	
}


void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const
	FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	/*RandomPatrol();*/
}