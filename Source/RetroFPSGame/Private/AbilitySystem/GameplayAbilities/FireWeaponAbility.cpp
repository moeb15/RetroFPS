// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilities/FireWeaponAbility.h"
#include "Interfaces/CombatInterface.h"

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
	return CombatInterface->FireWeapon_Implementation();
}
