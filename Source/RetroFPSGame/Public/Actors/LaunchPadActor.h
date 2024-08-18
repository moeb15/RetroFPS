// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPadActor.generated.h"

class UBoxComponent;

UCLASS()
class RETROFPSGAME_API ALaunchPadActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ALaunchPadActor();

	UFUNCTION()
	void LaunchActor(
		UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Launch Pad", 
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Launch Pad",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> CollisionBox;

	UPROPERTY(EditDefaultsOnly, Category = "Launch Pad",
		meta = (AllowPrivateAccess = "true"))
	float LaunchSpeed = 3000.f;;
};
