// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 400.0f;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	
	

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacter::MovementForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::PitchRot(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::StrafeMov(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::Jump1()
{
	ACharacter::Jump();
}

int APlayerCharacter::GetHP()
{
	return PlayerHP;
}

void APlayerCharacter::OnBeginFire()
{
	AController* pController = GetController();
	FVector CameraLoc;
	FRotator CameraRot;
	pController->GetPlayerViewPoint(CameraLoc, CameraRot);
	float CastRange = 10000.0f;
	FVector EndPoint = CameraLoc + CameraRot.Vector() * CastRange;

	FHitResult HitRes;

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitRes, CameraLoc, EndPoint, ECC_Visibility);
	if (bHit)
	{
		HitRes.GetActor()->Destroy();
	}
}

void APlayerCharacter::OnEndFire()
{
}

