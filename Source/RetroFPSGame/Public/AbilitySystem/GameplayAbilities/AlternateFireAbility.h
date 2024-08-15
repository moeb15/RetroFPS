// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GA_FPSAbility.h"
#include "AlternateFireAbility.generated.h"

class AProjectileActor;
/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UAlternateFireAbility : public UGA_FPSAbility
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	TSubclassOf<AProjectileActor> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> CostEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffect;

	UFUNCTION(BlueprintCallable, Category = Projectile)
	void SpawnProjectile();
};
