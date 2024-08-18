// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KillingFloorActor.generated.h"

class UGameplayEffect;
UCLASS()
class RETROFPSGAME_API AKillingFloorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AKillingFloorActor();

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor);

public:
	UPROPERTY(EditDefaultsOnly, Category = "Effect Class")
	TSubclassOf<UGameplayEffect> ActorEffectClass;

};
