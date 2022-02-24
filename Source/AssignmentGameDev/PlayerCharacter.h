// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Grenade.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneCaptureComponent2D;

UCLASS()
class ASSIGNMENTGAMEDEV_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	UFUNCTION()
		void MovementForward(float Value);
	UFUNCTION()
		void PitchRot(float Value);
	UFUNCTION()
		void StrafeMov(float Value);
	UFUNCTION()
		void Turn(float Value);
	UFUNCTION()
		void OnBeginFire();	
	UFUNCTION()
		void Jump1();
	UFUNCTION()
		void Throw();
	UFUNCTION()
		int GetHP();
	UFUNCTION()
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

private:
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* MapArm;
	UPROPERTY(EditAnywhere)
		USceneCaptureComponent2D* MapCamera;
	UPROPERTY(EditAnywhere)
		float PlayerHP = 100;
	UPROPERTY(EditAnywhere)
		float PlayerFireDamage = 50;
	UPROPERTY(EditAnywhere)
		USoundBase* FireSound;
	UPROPERTY(EditAnywhere)
		USceneComponent* GrenadeSpawn;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AGrenade> GrenadeClass;

	




	
};
