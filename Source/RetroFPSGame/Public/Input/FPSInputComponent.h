// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "AbilitySystem/Input/InputConfig.h"
#include "FPSInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UFPSInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserClass, typename PressedFuncType, typename HeldFuncType, typename ReleasedFuncType>
	void BindAbilityActions(
		const UInputConfig* InputConfig,
		UserClass* Object,
		PressedFuncType PressedFunc,
		HeldFuncType HeldFunc,
		ReleasedFuncType ReleasedFunc);
};

template<class UserClass, typename PressedFuncType, typename HeldFuncType, typename ReleasedFuncType>
inline void UFPSInputComponent::BindAbilityActions(
	const UInputConfig* InputConfig, 
	UserClass* Object, 
	PressedFuncType PressedFunc, 
	HeldFuncType HeldFunc, 
	ReleasedFuncType ReleasedFunc)
{
	check(InputConfig);
	for (const FRetroInputAction& Action : InputConfig->AbilityInputActions) {
		if (Action.InputAction && Action.InputTag.IsValid()) {
			if (HeldFunc) {
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, Action.InputTag);
			}
			if (PressedFunc) {
				BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunc, Action.InputTag);
			}
			if (ReleasedFunc) {
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag);
			}
		}
	}
}
