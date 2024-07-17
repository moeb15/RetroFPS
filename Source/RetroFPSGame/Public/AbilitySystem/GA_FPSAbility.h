// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayTagContainer.h"
#include "GA_FPSAbility.generated.h"


class UGameplayEffect;
class UAbilityTask_WaitGameplayEvent;
class UAbilityTask_WaitDelay;
/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UGA_FPSAbility : public UGameplayAbility
{
	GENERATED_BODY()
/*
protected:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData) override;

public:
	UFUNCTION(BlueprintNativeEvent)
	void FireWeapon();
	virtual void FireWeapon_Implementation() = 0;

	UFUNCTION(BlueprintCallable)
	void WaitFor();

	virtual bool CommitAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Tags",
		meta = (AllowPrivateAccess = "true"))
	FGameplayTag WeaponEventTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Task",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilityTask_WaitGameplayEvent> GameplayEventWaitTask;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Tags",
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> WeaponGameplayEffectClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Task",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilityTask_WaitDelay> GameplayEventWaitDelayTask;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Task",
		meta = (AllowPrivateAccess = "true"))
	float AbilityCooldown = 1.0f;*/
};
