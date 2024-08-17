// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;
class UOverlayWidgetController;
class UStatusWidget;
/**
 * 
 */
UCLASS()
class RETROFPSGAME_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void InitHUD(UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UOverlayWidgetController* GetOverlayWidgetController(UAbilitySystemComponent* ASC, UAttributeSet* AS);


	UPROPERTY()
	TObjectPtr<UStatusWidget> StatusWidget;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widget Controller",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditDefaultsOnly, Category = "Overlay Widget Controller",
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UStatusWidget> StatusWidgetClass;
};
