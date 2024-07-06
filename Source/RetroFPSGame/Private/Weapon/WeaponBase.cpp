// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponBase.h"
#include "Components/SceneCaptureComponent2D.h"
#include "PaperFlipbookComponent.h"
#include "Components/PointLightComponent.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Camera = CreateDefaultSubobject<USceneCaptureComponent2D>("Camera");
	Camera->SetupAttachment(RootComponent);

	WeaponFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>("Weapon Flipbook");
	WeaponFlipbook->SetupAttachment(Camera);

	PointLight = CreateDefaultSubobject<UPointLightComponent>("Point Light");
	PointLight->SetupAttachment(Camera);
}

void AWeaponBase::InitializeWeapon_Implementation()
{
	WeaponFlipbook->SetFlipbook(nullptr);
	WeaponFlipbook->SetHiddenInGame(true);
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

