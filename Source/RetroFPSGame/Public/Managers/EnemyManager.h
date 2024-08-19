// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_MULTICAST_DELEGATE(FOnEnemyDestroyedSignature);

/**
 * 
 */
class RETROFPSGAME_API EnemyManager
{
public:
	static EnemyManager& Get();
	static void InitializeEnemy();
	static void EnemyDestroyed();
	static int GetEnemyCount();

	FOnEnemyDestroyedSignature OnEnemyDestroyed;

private:
	static EnemyManager s_Instance;
	int EnemyCount = 0;
};
