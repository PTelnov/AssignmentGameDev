// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedBarrel.generated.h"

class AAssignmentGameDevGameModeBase;

UCLASS()
class ASSIGNMENTGAMEDEV_API ARedBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BarrelMesh;
	UPROPERTY()
		AAssignmentGameDevGameModeBase* GameModeRef; // Reference to the game mode
	UPROPERTY(EditAnywhere)
		float barrelHP = 1500.0f; // Health of the barrel

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

};
