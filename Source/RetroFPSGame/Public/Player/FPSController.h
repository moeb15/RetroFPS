// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "FPSController.generated.h"

class UInputAction;
class UInputMappingContext;
class UInputConfig;
class UFPSAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API AFPSController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFPSController();
	UFPSAbilitySystemComponent* GetASC();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UFPSAbilitySystemComponent> ASC;

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void AbilityHeldAction(FGameplayTag InputTag);
	void AbilityPressedAction(FGameplayTag InputTag);
	void AbilityReleasedAction(FGameplayTag InputTag);
};
