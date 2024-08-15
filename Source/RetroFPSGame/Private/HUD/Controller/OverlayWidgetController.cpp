// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/Controller/OverlayWidgetController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/FPSAbilitySystemComponent.h"
#include "AbilitySystem/FPSAttributeSet.h"
#include "Kismet/GameplayStatics.h"


void UOverlayWidgetController::BroadcastInitialValues()
{
	const UFPSAttributeSet* FPSAS = CastChecked<UFPSAttributeSet>(AS);
	
	OnHealthChanged.Broadcast(FPSAS->GetHealth());
	OnMaxHealthChanged.Broadcast(FPSAS->GetMaxHealth());

	OnManaChanged.Broadcast(FPSAS->GetMana());
	OnMaxManaChanged.Broadcast(FPSAS->GetMaxMana());

	OnArmourChanged.Broadcast(FPSAS->GetArmour());
	OnMaxArmourChanged.Broadcast(FPSAS->GetMaxArmour());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UFPSAttributeSet* FPSAS = CastChecked<UFPSAttributeSet>(AS);

	ASC->GetGameplayAttributeValueChangeDelegate(
		FPSAS->GetHealthAttribute()
	).AddLambda(
		[this](const FOnAttributeChangeData& Data) {
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(
		FPSAS->GetMaxHealthAttribute()
	).AddLambda(
		[this](const FOnAttributeChangeData& Data) {
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(
		FPSAS->GetManaAttribute()
	).AddLambda(
		[this](const FOnAttributeChangeData& Data) {
			OnManaChanged.Broadcast(Data.NewValue);
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(
		FPSAS->GetMaxManaAttribute()
	).AddLambda(
		[this](const FOnAttributeChangeData& Data) {
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(
		FPSAS->GetArmourAttribute()
	).AddLambda(
		[this](const FOnAttributeChangeData& Data) {
			OnArmourChanged.Broadcast(Data.NewValue);
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(
		FPSAS->GetMaxArmourAttribute()
	).AddLambda(
		[this](const FOnAttributeChangeData& Data) {
			OnMaxArmourChanged.Broadcast(Data.NewValue);
		}
	);
}
