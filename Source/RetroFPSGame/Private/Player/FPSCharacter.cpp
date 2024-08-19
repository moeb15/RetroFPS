// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ChildActorComponent.h"
#include "Weapon/WeaponBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/FPSController.h"
#include "Components/PointLightComponent.h"
#include "HUD/FPSHUD.h"

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

	GetCharacterMovement()->MaxWalkSpeed = 800.f;
	GetCharacterMovement()->AirControl = 0.9f;
}

FHitResult AFPSCharacter::FireWeapon_Implementation()
{
	if (WeaponType->ImplementsInterface(UIPlayerWeapon::StaticClass())) {
		IIPlayerWeapon::Execute_SwapFlipbook(WeaponActor->GetChildActor());
		AWeaponBase* CurWeapon = Cast<AWeaponBase>(WeaponActor->GetChildActor());
		if (CurWeapon->CanFire()) {
			CurWeapon->GetLight()->SetHiddenInGame(false);
			const FVector StartLoc = FirstPersonCamera->GetComponentLocation();
			const FVector EndLoc = StartLoc + FirstPersonCamera->GetForwardVector() * 50000.f;

			FHitResult BulletHitResult;
			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(this);
			GetWorld()->LineTraceSingleByChannel(
				BulletHitResult,
				StartLoc,
				EndLoc,
				ECC_Visibility,
				CollisionParams);

			//DrawDebugLine(GetWorld(), StartLoc, EndLoc, FColor::Blue, false, 3.f);
			return BulletHitResult;
		}
	}
	return FHitResult();
}

FTransform AFPSCharacter::GetAlternateFireTransform_Implementation()
{
	FTransform AlternateFireTransform;
	AlternateFireTransform.SetLocation(GetActorLocation() + ( GetActorUpVector() + GetActorForwardVector()) * 10);
	AlternateFireTransform.SetRotation(GetActorQuat());
	return AlternateFireTransform;
}

bool AFPSCharacter::CanAlternateFire() const
{
	AWeaponBase* CurWeapon = Cast<AWeaponBase>(WeaponActor->GetChildActor());
	return CurWeapon->CanFire();
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = Cast<APlayerController>(GetController());
	check(PC);
	AFPSHUD* HUD = Cast<AFPSHUD>(PC->GetHUD());
	check(HUD);
	HUD->InitHUD(GetAbilitySystemComponent(), GetAttributeSet());

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


