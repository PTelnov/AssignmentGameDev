// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "AssignmentGameDevGameModeBase.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));// Creates a spring arm
	
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
	GameModeRef = Cast<AAssignmentGameDevGameModeBase>(GetWorld()->GetAuthGameMode()); // Gets current game mode
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacter::MovementForward(float Value) // Moves player forward/backwards
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

float APlayerCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)// Decreases player health and if player health is less than 0, opens a lose screen
{
	
	PlayerHP -= DamageAmount;
	if (PlayerHP <= 0)
	{
		GameModeRef->GameOver(false);
	}
	return DamageAmount;
	
}

void APlayerCharacter::OnBeginFire()
{
	AController* pController = GetController(); // Gets player controller
	FVector CameraLoc;
	FRotator CameraRot;
	pController->GetPlayerViewPoint(CameraLoc, CameraRot); // Gets player Location and Rotation
	float CastRange = 10000.0f; // Length of the ray
	FVector EndPoint = CameraLoc + CameraRot.Vector() * CastRange; // Calculates end point of the ray

	FHitResult HitRes;
	UGameplayStatics::PlaySoundAtLocation( // Plays the fire sound at the player's location
		GetWorld(),
		FireSound,
		GetActorLocation(),
		1.0f,
		1.0f,
		0.0f);


	FCollisionQueryParams AdditionalParam;
	AdditionalParam.AddIgnoredActor(this); // Player character will be ignored in Ray cast. Needed to avoid player character being shoot by himself.


	bool bHit = GetWorld()->LineTraceSingleByChannel(HitRes, CameraLoc, EndPoint, ECC_Visibility, AdditionalParam); // Raycast from player
	if (bHit) // if Hit was successful, apply damage to other actor
	{
		UGameplayStatics::ApplyDamage(
			HitRes.GetActor(), //actor that will be damaged
			PlayerFireDamage, //the player damage to apply
			pController, //controller that caused the damage
			this, //Actor that caused the damage
			UDamageType::StaticClass() 
		);
	}
}

void APlayerCharacter::Throw() // Spawns a grenade in front of the player
{
	if (GrenadeClass) { 
		FVector SpawnLocation = GrenadeSpawn->GetComponentLocation();
		FRotator SpawnRotation = GrenadeSpawn->GetComponentRotation();
		AGrenade* TempGrenade = GetWorld()->SpawnActor<AGrenade>(GrenadeClass, SpawnLocation, SpawnRotation); // Spawns a grenade
		TempGrenade->SetOwner(this); // Sets player as owner of the grenade
	}

	
}




