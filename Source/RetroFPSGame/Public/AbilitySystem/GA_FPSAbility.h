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

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartInputTag;
};
