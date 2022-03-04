// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AAIController* aiCont = OwnerComp.GetAIOwner();
	FVector Loc;
	FRotator Rot;
	aiCont->GetPlayerViewPoint(Loc, Rot); // Gets AI view point
	float CastRange = 10000.0f; // End point of the ray
	FVector EndPoint = Loc + Rot.Vector() * CastRange;

	FHitResult HitRes;
	UGameplayStatics::PlaySoundAtLocation( // Plays the fire sound at AI's location
		GetWorld(),
		FireSound,
		aiCont->GetPawn()->GetActorLocation(),
		1.0f,
		1.0f,
		0.0f);


	FCollisionQueryParams AdditionalParam; // Added to avoid AIs shooting themselves.

	AdditionalParam.AddIgnoredActor(aiCont->GetPawn()); // Added to avoid AIs shooting themselves.


	bool bHit = GetWorld()->LineTraceSingleByChannel(HitRes, Loc, EndPoint, ECC_Visibility, AdditionalParam);
	if (bHit)
	{

		UGameplayStatics::ApplyDamage(
			HitRes.GetActor(), //actor that will be damaged
			EnemyFireDamage, //the enemy damage to apply
			aiCont, //controller that caused the damage
			aiCont->GetPawn(), //Actor that actually caused the damage
			UDamageType::StaticClass() 
		);
	}
	return EBTNodeResult::Succeeded;
}