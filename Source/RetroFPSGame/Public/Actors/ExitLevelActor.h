// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitLevelActor.generated.h"

UCLASS()
class RETROFPSGAME_API AExitLevelActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AExitLevelActor();

	UFUNCTION(BlueprintCallable)
	void ExitLevel(AActor* PlayerActor);

};
