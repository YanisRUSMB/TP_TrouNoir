#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

class USphereComponent;
class UNiagaraComponent;
class UProjectileMovementComponent;
class URadialForceComponent;
class UStaticMeshComponent;

UCLASS()
class TP_TROUNOIR_API ABlackHole : public AActor
{
	GENERATED_BODY()

public:

	ABlackHole();

protected:

	virtual void BeginPlay() override;
	
	void Explode();
	void Impulse();
	void Delete();
	bool ShouldDeleteActor(const AActor* Actor) const;
	
	FTimerHandle TimerHandle_Explosion;
	FTimerHandle TimerHandle_Deletion;
	FTimerHandle TimerHandle_Force;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool IsExploding;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* CollisionSphere;

	UPROPERTY(BlueprintReadWrite)
	UNiagaraComponent* BulletFX;

	UPROPERTY(BlueprintReadWrite)
	UProjectileMovementComponent* ProjectileComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	URadialForceComponent* RadialForceComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess))
	UStaticMeshComponent* StaticMeshComponent;

public:

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
