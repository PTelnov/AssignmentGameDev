// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"

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

	MapArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MapArm"));
	MapArm->SetupAttachment(RootComponent);

	MapCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Map Camera"));
	MapCamera->SetupAttachment(MapArm, USpringArmComponent::SocketName);

	GrenadeSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Grenade Spawn"));
	GrenadeSpawn->SetupAttachment(RootComponent);
	

	
	

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

float APlayerCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	
	PlayerHP -= DamageAmount;
	if (PlayerHP <= 0)
	{
		
	}
	return DamageAmount;
	
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
	UGameplayStatics::PlaySoundAtLocation(
		GetWorld(),
		FireSound,
		GetActorLocation(),
		1.0f,
		1.0f,
		0.0f);


	bool bHit = GetWorld()->LineTraceSingleByChannel(HitRes, CameraLoc, EndPoint, ECC_Visibility);
	if (bHit)
	{
		UGameplayStatics::ApplyDamage(
			HitRes.GetActor(), //actor that will be damaged
			PlayerFireDamage, //the base damage to apply
			pController, //controller that caused the damage
			this, //Actor that actually caused the damage
			UDamageType::StaticClass() //class that describes the damage that was done
		);
	}
}

void APlayerCharacter::Throw()
{
	if (GrenadeClass) { //checks teabag projectile has been set in the editor
		FVector SpawnLocation = GrenadeSpawn->GetComponentLocation();
		FRotator SpawnRotation = GrenadeSpawn->GetComponentRotation();
		AGrenade* TempGrenade = GetWorld()->SpawnActor<AGrenade>(GrenadeClass, SpawnLocation, SpawnRotation);
	}

	
}




