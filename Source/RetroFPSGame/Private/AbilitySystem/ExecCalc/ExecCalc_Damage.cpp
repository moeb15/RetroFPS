// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ExecCalc/ExecCalc_Damage.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/FPSAttributeSet.h"
#include "Interfaces/CombatInterface.h"
#include "FPSGameplayTags.h"

struct FPSDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armour)
	
	FPSDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UFPSAttributeSet, Armour, Target, false);
	}
};

static const FPSDamageStatics& DamageStatics()
{
	static FPSDamageStatics DStatics;
	return DStatics;
}

UExecCalc_Damage::UExecCalc_Damage()
{
	RelevantAttributesToCapture.Add(DamageStatics().ArmourDef);
}

void UExecCalc_Damage::Execute_Implementation(
	const FGameplayEffectCustomExecutionParameters& ExecutionParams, 
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
	const UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();

	AActor* SourceActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;
	AActor* TargetActor = TargetASC ? TargetASC->GetAvatarActor() : nullptr;

	ICombatInterface* SourceCombatInterface = Cast<ICombatInterface>(SourceActor);
	ICombatInterface* TargetCombatInterface = Cast<ICombatInterface>(TargetActor);

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = SourceTags;
	EvalParams.TargetTags = TargetTags;

	float Damage = Spec.GetSetByCallerMagnitude(FRetroFPSGameplayTags::Get().Damage);

	float ArmourVal = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmourDef, EvalParams, ArmourVal);
	ArmourVal = FMath::Max<float>(0.0f, ArmourVal);

	float ArmourDamage = 0.0f;

	bool bHasArmour = ArmourVal > 0.0f;
	if (bHasArmour) {
		Damage *= 0.5f;
		ArmourDamage = -Damage;
	}

	const FGameplayModifierEvaluatedData DamageEvalData(UFPSAttributeSet::GetIncomingDamageAttribute(), EGameplayModOp::Additive, Damage);
	const FGameplayModifierEvaluatedData ArmourEvalData(UFPSAttributeSet::GetArmourAttribute(), EGameplayModOp::Additive, ArmourDamage);
	OutExecutionOutput.AddOutputModifier(DamageEvalData);
	OutExecutionOutput.AddOutputModifier(ArmourEvalData);
}
