// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponPickup.generated.h"

class USphereComponent;
class UPaperFlipbookComponent;
class AWeaponBase;

UCLASS()
class RETROFPSGAME_API AWeaponPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponPickup();

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Pickup,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> PickupRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Pickup,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbookComponent> PickupFlipbook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Pickup,
		meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AWeaponBase> WeaponType;

	float ElapsedTime = 0.0f;
};
