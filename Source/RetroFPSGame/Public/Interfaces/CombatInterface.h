// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RETROFPSGAME_API ICombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FHitResult FireWeapon();
	virtual FHitResult FireWeapon_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FTransform GetAlternateFireTransform();
	virtual FTransform GetAlternateFireTransform_Implementation() = 0;

	virtual bool CanAlternateFire() const = 0;

	virtual void Die() const = 0;

};
