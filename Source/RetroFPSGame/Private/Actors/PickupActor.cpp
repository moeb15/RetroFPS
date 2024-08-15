// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickupActor.h"
#include "GameplayEffect.h"
#include "Player/FPSCharacter.h"
#include "AbilitySystemBlueprintLibrary.h"

APickupActor::APickupActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APickupActor::ApplyEffectToTarget(AActor* TargetActor)
{
	if (!ActorEffectClass) return;
	if (!Cast<AFPSCharacter>(TargetActor)) return;

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	FGameplayEffectContextHandle EffectContext = TargetASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(ActorEffectClass, 1.0f, EffectContext);
	TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);

	Destroy();
}