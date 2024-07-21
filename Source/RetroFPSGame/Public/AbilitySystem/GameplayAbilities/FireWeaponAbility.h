// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GA_FPSAbility.h"
#include "FireWeaponAbility.generated.h"

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UFireWeaponAbility : public UGA_FPSAbility
{
	GENERATED_BODY()
	
public:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle, 
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category = Weapon)
	FHitResult GetWeaponHitResult();
};
