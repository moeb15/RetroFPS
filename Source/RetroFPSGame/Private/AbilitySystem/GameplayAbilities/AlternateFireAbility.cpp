// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/AlternateFireAbility.h"
#include "Actors/ProjectileActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "FPSGameplayTags.h"
#include "Interfaces/CombatInterface.h"
#include "Player/FPSCharacter.h"
#include "Actors/ProjectileActor.h"

void UAlternateFireAbility::SpawnProjectile()
{
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface && CombatInterface->CanAlternateFire()) {
		FTransform ProjectileTransform = CombatInterface->GetAlternateFireTransform_Implementation();
		
		UAbilitySystemComponent* SourceASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
		FGameplayEffectContextHandle EffectContext = SourceASC->MakeEffectContext();
		EffectContext.AddSourceObject(GetAvatarActorFromActorInfo());
		
		FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(CostEffect, 1.0f, EffectContext);
		UFPSAttributeSet* FPSAttributeSet = Cast<AFPSCharacterBase>(GetAvatarActorFromActorInfo())->GetAttributeSet();
		
		if (FPSAttributeSet->GetMana() > 15.f) {
			SourceASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
			AProjectileActor* Projectile = GetWorld()->SpawnActorDeferred<AProjectileActor>(
				ProjectileClass,
				ProjectileTransform,
				GetOwningActorFromActorInfo(),
				Cast<APawn>(GetOwningActorFromActorInfo()),
				ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

			FGameplayEffectContextHandle DamageContext = SourceASC->MakeEffectContext();
			DamageContext.SetAbility(this);
			DamageContext.AddSourceObject(Projectile);
			FGameplayEffectSpecHandle DamageSpec = SourceASC->MakeOutgoingSpec(DamageEffect, 1.0f, DamageContext);

			Projectile->DamageEffectSpecHandle = DamageSpec;
			Projectile->FinishSpawning(ProjectileTransform);
		}
		else {
			return;
		}
	}
}
