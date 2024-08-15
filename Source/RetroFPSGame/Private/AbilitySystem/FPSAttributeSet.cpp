// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/FPSAttributeSet.h"
#include "GameplayEffectExtension.h"

UFPSAttributeSet::UFPSAttributeSet()
{
}

void UFPSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute()) {
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute()) {
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
	}
}
