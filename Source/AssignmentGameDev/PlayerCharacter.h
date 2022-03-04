// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Grenade.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneCaptureComponent2D;
class AAssignmentGameDevGameModeBase;

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
		void OnBeginFire();	//Fire a gun 
	UFUNCTION()
		void Jump1();// Jump function
	UFUNCTION()
		void Throw(); // Throw a grenade
	UFUNCTION()
		int GetHP();// Gets player HP 
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
		float PlayerHP = 100; // Player HP, can be changed in the blueprint
	UPROPERTY(EditAnywhere)
		float PlayerFireDamage = 50; // Damage of the player, can be changed in the blueprint
	UPROPERTY(EditAnywhere)
		USoundBase* FireSound; // Pointer to the fire sound
	UPROPERTY(EditAnywhere)
		USceneComponent* GrenadeSpawn;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AGrenade> GrenadeClass;
	UPROPERTY()
		AAssignmentGameDevGameModeBase* GameModeRef; // Reference to the game mode

	




	
};
