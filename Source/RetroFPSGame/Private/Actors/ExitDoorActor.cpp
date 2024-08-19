// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ExitDoorActor.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyCharacter.h"
#include "Managers/EnemyManager.h"

AExitDoorActor::AExitDoorActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AExitDoorActor::BeginPlay()
{
	Super::BeginPlay();

	EnemyManager::Get().OnEnemyDestroyed.AddUObject(this, &AExitDoorActor::EnemiesAlive);
}

void AExitDoorActor::EnemiesAlive()
{
	if (EnemyManager::GetEnemyCount() <= 0) 
	{
		Destroy();
	}
}