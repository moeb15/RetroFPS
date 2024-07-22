// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSCharacterBase.h"
#include "AbilitySystem/FPSAttributeSet.h"
#include "AbilitySystem/FPSAbilitySystemComponent.h"

// Sets default values
AFPSCharacterBase::AFPSCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UFPSAbilitySystemComponent>("AbilitySystemComp");
	Attributes = CreateDefaultSubobject<UFPSAttributeSet>("Attributes");
}

UAbilitySystemComponent* AFPSCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UFPSAttributeSet* AFPSCharacterBase::GetAttributeSet() const
{
	return Attributes;
}

// Called when the game starts or when spawned
void AFPSCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySystemComponent) {
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		
		if (DefaultAttributeEffects) {
			FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
			EffectContext.AddSourceObject(this);
			FGameplayEffectSpecHandle SpecHandle = 
				AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffects, 1, EffectContext);

			if (SpecHandle.IsValid()) {
				FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(
					*SpecHandle.Data.Get()
				);
			}
		}

		if (HasAuthority()) {
			AbilitySystemComponent->AddCharacterAbilities(DefaultAbilities);
		}
	}
}

FHitResult AFPSCharacterBase::FireWeapon_Implementation()
{
	return FHitResult();
}

