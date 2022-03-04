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
	PrimaryActorTick.bCanEverTick = false;
	GrenadeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Granade Mesh"));
	SetRootComponent(GrenadeMesh);
	
	GrenadeMesh->SetSimulatePhysics(true); // SImulates physics
	GrenadeMesh->SetNotifyRigidBodyCollision(true); // Adds an ability to fire OnHit events


	ProjMove = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjMove->MaxSpeed = MovSpeed;
	ProjMove->InitialSpeed = MovSpeed;
	InitialLifeSpan = 3.0f;

	RadForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("Force Component"));// Adds a radial force component to fire impulses
	RadForce->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void AGrenade::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &AGrenade::OnHit);
	GetWorld()->GetTimerManager().SetTimer(GrenadeTimer, this, &AGrenade::Explosion, grenadeSec, false);// Sets timer on the grenade, when time runs out calls Explosion() function
	

	
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
	
	
	if (OtherActor->ActorHasTag(TEXT("Barrel")) || OtherActor->ActorHasTag(TEXT("Dest"))) // Will only cause an explosion, if other actor is a barrel or a destructable object
	{
		
		if (GetOwner() == nullptr)
		{
			return;
		}
		Explosion();
	}
	
}

void AGrenade::Explosion()
{
	RadForce->FireImpulse(); // Fires an impulse
	TArray<AActor*> IgnoreActors; // An array of actors, which will be ignoring radial damage
	IgnoreActors.Add(GetOwner()); // Adds player to the ignored actors
	UGameplayStatics::ApplyRadialDamage(GetWorld(), GrenadeDamage, GetActorLocation(), ExplosionRad, UDamageType::StaticClass(), IgnoreActors, this, GetOwner()->GetInstigatorController()); // Applies radial damage in the ExplosionRad radius
	Destroy();

}



