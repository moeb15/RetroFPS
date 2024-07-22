// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponBase.h"
#include "Components/SceneCaptureComponent2D.h"
#include "PaperFlipbookComponent.h"
#include "Components/PointLightComponent.h"
#include "ActorSequenceComponent.h"
#include "ActorSequence.h"
#include "ActorSequencePlayer.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Camera = CreateDefaultSubobject<USceneCaptureComponent2D>("Camera");
	Camera->SetupAttachment(RootComponent);
	Camera->ProjectionType = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 426.f;

	WeaponFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>("Weapon Flipbook");
	WeaponFlipbook->SetupAttachment(Camera);
	WeaponFlipbook->SetRelativeLocation(FVector(0, 100, -50));
	WeaponFlipbook->SetRelativeRotation(FRotator(0, 0, 90));
	WeaponFlipbook->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponFlipbook->SetLooping(false);

	PointLight = CreateDefaultSubobject<UPointLightComponent>("Point Light");
	PointLight->SetupAttachment(Camera);
	PointLight->SetIntensity(10000.f);
	PointLight->SetAttenuationRadius(800.f);
	PointLight->SetHiddenInGame(true);

	WeaponBobAnim = CreateDefaultSubobject<UActorSequenceComponent>("Weapon Bob Animation");
}

void AWeaponBase::InitializeWeapon_Implementation()
{
	WeaponFlipbook->SetFlipbook(nullptr);
	WeaponFlipbook->SetHiddenInGame(true);
}

void AWeaponBase::SwapFlipbook_Implementation()
{
}

void AWeaponBase::SetCanFire(bool flag)
{
	bCanFire = flag;
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	Camera->ShowOnlyComponent(WeaponFlipbook);
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

