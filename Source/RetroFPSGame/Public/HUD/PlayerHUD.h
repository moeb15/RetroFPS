// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUD/Controller/OverlayWidgetController.h"
#include "PlayerHUD.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitHUD(UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UOverlayWidgetController* GetOverlayWidgetController(UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditDefaultsOnly, Category = "Overlay Widget Controller", 
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
