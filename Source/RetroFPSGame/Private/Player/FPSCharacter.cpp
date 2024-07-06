// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ChildActorComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "HUD/PlayerHUD.h"
#include "Weapon/WeaponBase.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 90.f);

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("First Person Camera");
	FirstPersonCamera->SetupAttachment(RootComponent);
	FirstPersonCamera->bUsePawnControlRotation = true;

	WeaponActor = CreateDefaultSubobject<UChildActorComponent>("Weapon Actor");
	WeaponActor->SetupAttachment(FirstPersonCamera);

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (PlayerHUDClass) {
		APlayerController* PC = Cast<APlayerController>(GetController());
		check(PC);
		PlayerHUD = CreateWidget<UPlayerHUD>(PC, PlayerHUDClass);
		check(PlayerHUD);
		PlayerHUD->AddToPlayerScreen();
	}
	if (WeaponType) {
		EquipWeapon(WeaponType);
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	if (APlayerController* PC = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* ELS = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer())) {
			ELS->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		// Moving
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Move);
		
		// Looking
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);
	}
}

void AFPSCharacter::EquipWeapon(TSubclassOf<AWeaponBase> WeaponClass)
{
	WeaponType = WeaponClass;
	WeaponActor->SetChildActorClass(WeaponType);
	if (WeaponType->ImplementsInterface(UIPlayerWeapon::StaticClass())) {
		IIPlayerWeapon::Execute_InitializeWeapon(WeaponActor->GetChildActor());
	}
}

void AFPSCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();
	
	if (Controller != nullptr && (InputValue.X != 0.0f || InputValue.Y != 0.0f)) {
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rot.Yaw, 0);
		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Forward, InputValue.Y);
		AddMovementInput(Right, InputValue.X);
	}
}

void AFPSCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();

	if (Controller != nullptr) {
		AddControllerYawInput(InputValue.X);
		AddControllerPitchInput(InputValue.Y);
	}
}

