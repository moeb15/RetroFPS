// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "FPSAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UFPSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UFPSAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData Armour;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, Armour);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, Mana);

};
