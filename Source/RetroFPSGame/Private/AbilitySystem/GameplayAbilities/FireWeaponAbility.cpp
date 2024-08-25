// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/FireWeaponAbility.h"
#include "Interfaces/CombatInterface.h"
#include "AbilitySystemComponent.h"
#include "DrawDebugHelpers.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "FPSGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"

void UFireWeaponAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData) 
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

}

FHitResult UFireWeaponAbility::GetWeaponHitResult()
{
	ICombatInterface* CombatInterface = CastChecked<ICombatInterface>(GetAvatarActorFromActorInfo());
	FHitResult WeaponHitResult = CombatInterface->FireWeapon_Implementation();
	if (WeaponHitResult.bBlockingHit) {
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(WeaponHitResult.GetActor())) {
			FGameplayEffectSpecHandle DamageEffectSpec = TargetASC->MakeOutgoingSpec(DamageEffectClass, 1.f, TargetASC->MakeEffectContext());
			UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(DamageEffectSpec, FRetroFPSGameplayTags::Get().Damage, Damage);
			TargetASC->ApplyGameplayEffectSpecToSelf(*DamageEffectSpec.Data.Get());

			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, BloodSplatterParticles, WeaponHitResult.ImpactPoint);
			//DrawDebugSphere(GetWorld(), WeaponHitResult.ImpactPoint, 10, 10, FColor::Red, false, 3.0f);
		}
		//DrawDebugSphere(GetWorld(), WeaponHitResult.ImpactPoint, 10, 10, FColor::Blue, false, 3.0f);
	}

	return WeaponHitResult;
}
