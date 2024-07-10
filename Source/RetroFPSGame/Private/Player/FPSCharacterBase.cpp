// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSCharacterBase.h"
#include "AbilitySystem/FPSAttributeSet.h"

// Sets default values
AFPSCharacterBase::AFPSCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	Attributes = CreateDefaultSubobject<UFPSAttributeSet>("Attributes");
}

UAbilitySystemComponent* AFPSCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
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
			for (TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities) {
				AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility.GetDefaultObject(), 1, 0));
			}
		}
	}
}

