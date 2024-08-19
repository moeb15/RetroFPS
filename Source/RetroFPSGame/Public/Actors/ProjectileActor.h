// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "ProjectileActor.generated.h"

class UNiagaraSystem;
class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class RETROFPSGAME_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectileActor();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

private:
	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 3.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> OverlapSphere;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactEffect;

public:
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	FGameplayEffectSpecHandle DamageEffectSpecHandle;
};
