// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player/FPSCharacterBase.h"
#include "FPSCharacter.generated.h"


class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UPlayerHUD;
class UChildActorComponent;
class UInputConfig;
class AWeaponBase;
struct FInputActionValue;

UCLASS()
class RETROFPSGAME_API AFPSCharacter : public AFPSCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	virtual void FireWeapon_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void EquipWeapon(TSubclassOf<AWeaponBase> WeaponClass);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = HUD,
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UPlayerHUD> PlayerHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> WeaponActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeaponBase> WeaponType;


	UPROPERTY()
	TObjectPtr<UPlayerHUD> PlayerHUD;

public:
	FORCEINLINE UCameraComponent* GetCameraComponent() const { return FirstPersonCamera; }
};
