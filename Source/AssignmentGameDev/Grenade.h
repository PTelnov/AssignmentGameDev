// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grenade.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;
class URadialForceComponent;

UCLASS()
class ASSIGNMENTGAMEDEV_API AGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		float MovSpeed = 1000.0f;
	UPROPERTY(EditAnywhere)
		float GrenadeDamage = 50.0f;
	UPROPERTY(EditAnywhere)
		float ExplosionRad = 100.0f;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* GrenadeMesh;
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjMove;
	UPROPERTY(EditAnywhere)
		URadialForceComponent* RadForce;
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
			const FHitResult& Hit);




};
