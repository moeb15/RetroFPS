// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OverlayWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class RETROFPSGAME_API UOverlayWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void BroadcastInitialValues();

	UFUNCTION(BlueprintCallable)
	void BindCallbacksToDependencies();

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnArmourChanged;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnMaxArmourChanged;

	UPROPERTY(VisibleAnywhere, Category = "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> ASC;

	UPROPERTY(VisibleAnywhere, Category = "Widget Controller")
	TObjectPtr<UAttributeSet> AS;
};
