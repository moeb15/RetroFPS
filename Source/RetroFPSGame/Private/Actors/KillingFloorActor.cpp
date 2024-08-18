// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/KillingFloorActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

AKillingFloorActor::AKillingFloorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}


void AKillingFloorActor::ApplyEffectToTarget(AActor* TargetActor)
{
	if (!ActorEffectClass) return;

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(ActorEffectClass, 1.0f, EffectContext);
	TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
}