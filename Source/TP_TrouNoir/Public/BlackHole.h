// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

class USphereComponent;

UCLASS()
class TP_TROUNOIR_API ABlackHole : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	class UNiagaraComponent* BulletFX;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* CollisionSphere;

	UPROPERTY(BlueprintReadWrite)
	class UProjectileMovementComponent* ProjectileComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	float Speed;

};