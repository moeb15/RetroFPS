// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/PlayerHUD.h"


void UPlayerHUD::InitHUD(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	check(OverlayWidgetControllerClass);

	UOverlayWidgetController* WC = GetOverlayWidgetController(ASC, AS);
	WC->BroadcastInitialValues();
}

UOverlayWidgetController* UPlayerHUD::GetOverlayWidgetController(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	if (OverlayWidgetController == nullptr) {
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->ASC = ASC;
		OverlayWidgetController->AS = AS;
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}
