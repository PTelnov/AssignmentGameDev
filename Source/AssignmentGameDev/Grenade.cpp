// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "EnemyCharacter.h"

// Sets default values
AGrenade::AGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GrenadeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Granade Mesh"));
	SetRootComponent(GrenadeMesh);
	
	GrenadeMesh->SetSimulatePhysics(true);
	GrenadeMesh->SetNotifyRigidBodyCollision(true);


	ProjMove = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjMove->MaxSpeed = MovSpeed;
	ProjMove->InitialSpeed = MovSpeed;
	InitialLifeSpan = 10.0f;

	RadForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("Force Component"));
	RadForce->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGrenade::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &AGrenade::OnHit);
	

	
}

// Called every frame
void AGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrenade::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == nullptr)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Called"));
	if (OtherActor->ActorHasTag(TEXT("Enemy")))
	{
		if (GetOwner() == nullptr)
		{
			return;
		}
		TArray<AActor*> IgnoreActors;
		

		UGameplayStatics::ApplyRadialDamage(GetWorld(), GrenadeDamage, GetActorLocation(), ExplosionRad, UDamageType::StaticClass(), IgnoreActors, this, GetOwner()->GetInstigatorController());
		RadForce->FireImpulse();
		Destroy();
	}

}



