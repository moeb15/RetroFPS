// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSController.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/Input/InputConfig.h"
#include "Input/FPSInputComponent.h"
#include "AbilitySystem/FPSAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

AFPSController::AFPSController()
{
	PrimaryActorTick.bCanEverTick = true;
}

UFPSAbilitySystemComponent* AFPSController::GetASC()
{
	return Cast<UFPSAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this));
}

void AFPSController::BeginPlay()
{
	Super::BeginPlay();
	check(DefaultMappingContext)

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) {
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AFPSController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UFPSInputComponent* FPSIC = Cast<UFPSInputComponent>(InputComponent)) {
		FPSIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSController::Move);
		FPSIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSController::Look);

		FPSIC->BindAbilityActions(
			InputConfig,
			this,
			&AFPSController::AbilityPressedAction,
			&AFPSController::AbilityHeldAction,
			&AFPSController::AbilityReleasedAction);
	}
	
}

void AFPSController::Move(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>()) {
		if (InputValue.X != 0.0f || InputValue.Y != 0.0f) {
			const FRotator Rot = ControlledPawn->Controller->GetControlRotation();
			const FRotator YawRotation(0, Rot.Yaw, 0);
			const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			ControlledPawn->AddMovementInput(Forward, InputValue.Y);
			ControlledPawn->AddMovementInput(Right, InputValue.X);
		}
	}
}

void AFPSController::Look(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>()) {
		if (InputValue.X != 0.0f || InputValue.Y != 0.0f) {
			ControlledPawn->AddControllerYawInput(InputValue.X);
			ControlledPawn->AddControllerPitchInput(InputValue.Y);
		}
	}
}

void AFPSController::AbilityHeldAction(FGameplayTag InputTag)
{
	if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
}

void AFPSController::AbilityPressedAction(FGameplayTag InputTag)
{

}

void AFPSController::AbilityReleasedAction(FGameplayTag InputTag)
{
	if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
}
