// Fill out your copyright notice in the Description page of Project Settings.


#include "RedBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "AssignmentGameDevGameModeBase.h"


// Sets default values
ARedBarrel::ARedBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel Mesh"));
	BarrelMesh->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void ARedBarrel::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = Cast<AAssignmentGameDevGameModeBase>(GetWorld()->GetAuthGameMode());// Gets current Game mode
	
}

// Called every frame
void ARedBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ARedBarrel::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) // Takes damage and if HP gets lower than 0, opens a win screen
{
	barrelHP -= DamageAmount;
	if (barrelHP <= 0)
	{
		
		GameModeRef->GameOver(true);
		
	}
	return DamageAmount;
}

