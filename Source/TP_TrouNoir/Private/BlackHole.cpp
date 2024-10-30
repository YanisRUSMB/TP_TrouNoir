#include "BlackHole.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "TimerManager.h"

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

	IsExploding = false;
}

void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Explosion, this, &ABlackHole::Explode, 3.0f, false);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Deletion, this, &ABlackHole::Delete, 10.0f, false);
	
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OnOverlapBegin);
}

void ABlackHole::Explode()
{
	IsExploding = true;
	ProjectileComponent->StopMovementImmediately();
	BulletFX->Activate();
	StaticMeshComponent->DestroyComponent();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Force, this, &ABlackHole::Impulse, .1f, true);
}

void ABlackHole::Impulse()
{
	if (RadialForceComponent)
	{
		RadialForceComponent->FireImpulse();
	}
}

void ABlackHole::Delete()
{
	Destroy();
}

bool ABlackHole::ShouldDeleteActor(const AActor* Actor) const
{
	return IsExploding &&
		Actor != this &&
		Actor->GetRootComponent()->Mobility == EComponentMobility::Movable &&
		!Actor->IsA(APawn::StaticClass());
}

void ABlackHole::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ShouldDeleteActor(OtherActor))
	{
		OtherActor->Destroy();
	}
}
