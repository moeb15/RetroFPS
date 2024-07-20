// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/FPSAbilitySystemComponent.h"
#include "AbilitySystem/GA_FPSAbility.h"

void UFPSAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{	
	for (const TSubclassOf<UGameplayAbility>& Ability : StartupAbilities) {
		FGameplayAbilitySpec Spec = FGameplayAbilitySpec(Ability, 1);
		if (UGA_FPSAbility* FPSAbility = Cast<UGA_FPSAbility>(Spec.Ability)) {
			Spec.DynamicAbilityTags.AddTag(FPSAbility->StartInputTag);
			GiveAbility(Spec);
		}
	}
}

void UFPSAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& Spec : GetActivatableAbilities()) {
		if (Spec.DynamicAbilityTags.HasTagExact(InputTag)) {
			AbilitySpecInputPressed(Spec);
			if (!Spec.IsActive()) {
				TryActivateAbility(Spec.Handle);
			}
		}
	}
}

void UFPSAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& Spec : GetActivatableAbilities()) {
		if (Spec.DynamicAbilityTags.HasTagExact(InputTag)) {
			AbilitySpecInputReleased(Spec);
		}
	}
}
