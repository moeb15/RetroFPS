// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemInterface.h"
#include "FPSCharacterBase.generated.h"

class UFPSAbilitySystemComponent;
class UFPSAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

UCLASS()
class RETROFPSGAME_API AFPSCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, 
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UFPSAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UFPSAttributeSet> Attributes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RetroFPS,
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> DefaultAttributeEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RetroFPS,
		meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

};
