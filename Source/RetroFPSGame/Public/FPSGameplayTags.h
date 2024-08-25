// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
// Singleton containing native gameplay tags
struct FRetroFPSGameplayTags 
{
	static const FRetroFPSGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Input_LMB;
	FGameplayTag Input_RMB;
	FGameplayTag Input_R;

	FGameplayTag Attributes_Primary_Health;
	FGameplayTag Attributes_Primary_Armour;
	FGameplayTag Attributes_Primary_Mana;

	FGameplayTag Damage;

private:
	static FRetroFPSGameplayTags GameplayTags;
};