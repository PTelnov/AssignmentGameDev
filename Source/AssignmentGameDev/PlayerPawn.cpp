// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*PlayerInputComponent->BindAxis("Move Forwards", this, &APlayerPawn::MovementForward);
	PlayerInputComponent->BindAxis("Look up", this, &APlayerPawn::PitchRot);
	PlayerInputComponent->BindAxis("Strafe", this, &APlayerPawn::StrafeMov);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerPawn::YawRot);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPawn::OnBeginFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerPawn::OnEndFire);*/


}


