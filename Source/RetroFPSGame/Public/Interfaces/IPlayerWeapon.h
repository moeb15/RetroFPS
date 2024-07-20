// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerWeapon.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIPlayerWeapon : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RETROFPSGAME_API IIPlayerWeapon
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void InitializeWeapon();
	virtual void InitializeWeapon_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent)
	void SwapFlipbook();
	virtual void SwapFlipbook_Implementation() = 0;
};
