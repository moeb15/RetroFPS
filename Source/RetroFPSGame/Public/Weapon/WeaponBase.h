// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IPlayerWeapon.h"
#include "WeaponBase.generated.h"

class USceneCaptureComponent2D;
class UPaperFlipbookComponent;
class UPointLightComponent;

UCLASS()
class RETROFPSGAME_API AWeaponBase : public AActor, public IIPlayerWeapon
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	virtual void InitializeWeapon_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneCaptureComponent2D> Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbookComponent> WeaponFlipbook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPointLightComponent> PointLight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
