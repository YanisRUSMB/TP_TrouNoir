// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"


// Sets default values
ABlackHole::ABlackHole()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	SetRootComponent(CollisionSphere);
	BulletFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Effet"));
	BulletFX->SetupAttachment(CollisionSphere);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(CollisionSphere);

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>(TEXT("Radial Force"));
	RadialForceComponent->SetupAttachment(CollisionSphere);

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile movements"));
	ProjectileComponent->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	RadialForceComponent->AttachToComponent(CollisionSphere,FAttachmentTransformRules::KeepRelativeTransform);
}

