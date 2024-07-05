// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UPlayerHUD;
struct FInputActionValue;

UCLASS()
class RETROFPSGAME_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = HUD,
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UPlayerHUD> PlayerHUDClass;

	UPROPERTY()
	TObjectPtr<UPlayerHUD> PlayerHUD;

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

public:
	FORCEINLINE UCameraComponent* GetCameraComponent() const { return FirstPersonCamera; }
};
