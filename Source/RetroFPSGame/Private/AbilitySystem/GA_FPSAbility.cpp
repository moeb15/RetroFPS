// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GA_FPSAbility.h"
/*#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Abilities/Tasks/AbilityTask_WaitDelay.h"

void UGA_FPSAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	if (CommitAbility(Handle, ActorInfo, ActivationInfo)) {
		WaitFor();
		FireWeapon();
		GameplayEventWaitDelayTask = UAbilityTask_WaitDelay::WaitDelay(this, AbilityCooldown);
		EndAbility()
		GameplayEventWaitDelayTask->OnFinish.AddDynamic()
	}

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UGA_FPSAbility::WaitFor()
{
	GameplayEventWaitTask = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, WeaponEventTag);
	UAbilitySystemComponent* OwnerASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(
		GameplayEventWaitTask->GetOwnerActor());

	if (OwnerASC && GameplayEventWaitTask->IsFinished()) {
		FGameplayEffectContextHandle GE_Handle = OwnerASC->MakeEffectContext();
		FGameplayEffectSpecHandle GE_Spec = OwnerASC->MakeOutgoingSpec(WeaponGameplayEffectClass, 1, GE_Handle);
		OwnerASC->ApplyGameplayEffectSpecToTarget(*GE_Spec.Data.Get(),
			GameplayEventWaitTask->GetTargetASC());
	}
}

bool UGA_FPSAbility::CommitAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	OUT FGameplayTagContainer* OptionalRelevantTags)
{
	return Super::CommitAbility(Handle, ActorInfo, ActivationInfo, OptionalRelevantTags);
}
*/