// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/WeaponBase.h"
#include "Pistol.generated.h"

class UPaperFlipbook;

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API APistol : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	APistol();

	virtual void InitializeWeapon_Implementation() override;
	virtual void SwapFlipbook_Implementation() override;

	UFUNCTION()
	void StopFiring();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Animations",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbook> Idle_Flipbook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Animations",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbook> Fire_Flipbook;
};
