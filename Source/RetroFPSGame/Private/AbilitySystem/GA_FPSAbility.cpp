// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GA_FPSAbility.h"
#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"

void UGA_FPSAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	CommitAbility(Handle, ActorInfo, ActivationInfo);

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

UAbilityTask_WaitGameplayEvent* UGA_FPSAbility::WaitFor()
{
	GameplayEventWaitTask = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, WeaponEventTag);
	//ApplyGameplayEffectSpecToTarget();
	return GameplayEventWaitTask;
}

bool UGA_FPSAbility::CommitAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	OUT FGameplayTagContainer* OptionalRelevantTags)
{

	return false;
}
