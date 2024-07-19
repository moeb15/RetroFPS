// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Input/InputConfig.h"

const UInputAction* UInputConfig::FindAbilityInputAction(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FRetroInputAction& IA : AbilityInputActions) {
		if (IA.InputTag == InputTag) {
			return IA.InputAction;
		}
	}

	if (bLogNotFound) {
		UE_LOG(LogTemp, Error, TEXT("Input tag %s not found in %s"), *InputTag.ToString(), *GetClass()->GetName());
	}
	return nullptr;
}
