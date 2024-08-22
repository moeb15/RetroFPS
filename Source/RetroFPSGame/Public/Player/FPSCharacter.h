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

	virtual FHitResult FireWeapon_Implementation() override;
	virtual FTransform GetAlternateFireTransform_Implementation() override;
	virtual bool CanAlternateFire() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Die() const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void EquipWeapon(TSubclassOf<AWeaponBase> WeaponClass);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> WeaponActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeaponBase> WeaponType;

public:
	FORCEINLINE UCameraComponent* GetCameraComponent() const { return FirstPersonCamera; }
};
