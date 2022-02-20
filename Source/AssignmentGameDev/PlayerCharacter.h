// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

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
		void OnEndFire();
	UFUNCTION()
		void Jump1();
	UFUNCTION()
		int GetHP();

private:
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
		int PlayerHP = 50;

	
};
