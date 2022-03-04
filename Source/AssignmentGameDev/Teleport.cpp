// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleport.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATeleport::ATeleport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TeleportMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Teleport Mesh")); // Creates a mesh of the teleport
	SetRootComponent(TeleportMesh);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision box component")); // Creates a collision box
	BoxComp->SetupAttachment(TeleportMesh);

	BoxComp->SetCollisionProfileName("Trigger");

}

// Called when the game starts or when spawned
void ATeleport::BeginPlay()
{
	Super::BeginPlay();
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ATeleport::OnOverlapBegin); //Adds a delegate function on overlap
	
}

// Called every frame
void ATeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleport::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::OpenLevel(GetWorld(), Map); // Opens a level specified in the "Map" variable
}

