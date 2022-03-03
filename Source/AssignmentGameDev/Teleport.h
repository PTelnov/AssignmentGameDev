// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Teleport.generated.h"

class UBoxComponent;

UCLASS()
class ASSIGNMENTGAMEDEV_API ATeleport : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleport();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TeleportMesh;
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComp;
	UPROPERTY(EditAnywhere)
		FName Map = "GameMap";
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	



};
