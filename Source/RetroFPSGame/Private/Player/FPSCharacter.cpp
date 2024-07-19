// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ChildActorComponent.h"
#include "HUD/PlayerHUD.h"
#include "Weapon/WeaponBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/FPSController.h"

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

	bool isMoving = GetCharacterMovement()->Velocity.Size() > 0;
	AWeaponBase* Weapon = Cast<AWeaponBase>(WeaponActor->GetChildActor());
	Weapon->WeaponBob(isMoving, DeltaTime);
}

void AFPSCharacter::EquipWeapon(TSubclassOf<AWeaponBase> WeaponClass)
{
	WeaponType = WeaponClass;
	WeaponActor->SetChildActorClass(WeaponType);
	if (WeaponType->ImplementsInterface(UIPlayerWeapon::StaticClass())) {
		IIPlayerWeapon::Execute_InitializeWeapon(WeaponActor->GetChildActor());
	}
}


