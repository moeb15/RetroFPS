// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"
#include "AbilitySystemComponent.h"
#include "HUD/Controller/OverlayWidgetController.h"
#include "HUD/StatusWidget.h"

void AFPSHUD::InitHUD(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	check(OverlayWidgetControllerClass);
	check(StatusWidgetClass);

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), StatusWidgetClass);
	StatusWidget = Cast<UStatusWidget>(Widget);

	UOverlayWidgetController* WC = GetOverlayWidgetController(ASC, AS);

	StatusWidget->SetWidgetController(WC);

	WC->BroadcastInitialValues();

	Widget->AddToViewport();
}

UOverlayWidgetController* AFPSHUD::GetOverlayWidgetController(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	if (OverlayWidgetController == nullptr) {
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->ASC = ASC;
		OverlayWidgetController->AS = AS;
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}
