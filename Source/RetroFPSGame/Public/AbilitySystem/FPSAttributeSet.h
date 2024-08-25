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


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY();
	
	FEffectProperties() {}

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
	
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;

	FGameplayEffectContextHandle Handle;
};
/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UFPSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UFPSAttributeSet();

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	void SetEffectProperties(const struct FGameplayEffectModCallbackData& Data, FEffectProperties& Props);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData Armour;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, Armour);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData MaxArmour;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, MaxArmour);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UFPSAttributeSet, IncomingDamage);

};
