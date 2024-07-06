// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponPickup.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"
#include "Player/FPSCharacter.h"
#include "Weapon/WeaponBase.h"

// Sets default values
AWeaponPickup::AWeaponPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupRadius = CreateDefaultSubobject<USphereComponent>("Pickup Radius");
	PickupRadius->SetupAttachment(RootComponent);
	PickupRadius->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PickupRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	PickupFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>("Weapon Flipbook");
	PickupFlipbook->SetupAttachment(PickupRadius);

	PickupRadius->OnComponentBeginOverlap.AddDynamic(this, &AWeaponPickup::OnOverlapBegin);
}

void AWeaponPickup::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult)
{
	if (AFPSCharacter* FPS = Cast<AFPSCharacter>(OtherActor)) {
		if (WeaponType) {
			FPS->EquipWeapon(WeaponType);
			Destroy();
		}
	}
}

// Called every frame
void AWeaponPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rot{ PickupFlipbook->GetRelativeRotation() };
	FVector Pos{ PickupFlipbook->GetRelativeLocation() };
	Rot.Yaw += 15.f * DeltaTime;
	Pos.Z = 10.f * FMath::Sin(ElapsedTime);
	PickupFlipbook->SetRelativeLocation(Pos);
	PickupFlipbook->SetRelativeRotation(Rot);

	ElapsedTime += DeltaTime;
}

