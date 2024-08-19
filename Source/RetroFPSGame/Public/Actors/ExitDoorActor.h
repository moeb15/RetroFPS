// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitDoorActor.generated.h"

class AEnemyCharacter;
UCLASS()
class RETROFPSGAME_API AExitDoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AExitDoorActor();

	void EnemiesAlive();

protected:
	virtual void BeginPlay() override;

};
