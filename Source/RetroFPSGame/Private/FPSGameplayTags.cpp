// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameplayTags.h"
#include "GameplayTagsManager.h"

FRetroFPSGameplayTags FRetroFPSGameplayTags::GameplayTags;

void FRetroFPSGameplayTags::InitializeNativeGameplayTags() {
	GameplayTags.Input_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.LMB"), FString("Left mouse button"));
	GameplayTags.Input_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.RMB"), FString("Right mouse button"));
	GameplayTags.Input_R = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.R"), FString("R key"));

	GameplayTags.Attributes_Primary_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Health"), FString("Health attribute"));
	GameplayTags.Attributes_Primary_Armour = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Armour"), FString("Armour attribute, increases damage reduction"));
	GameplayTags.Attributes_Primary_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Mana"), FString("Mana"));
}
