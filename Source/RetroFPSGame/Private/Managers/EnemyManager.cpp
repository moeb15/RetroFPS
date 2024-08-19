// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/EnemyManager.h"

EnemyManager EnemyManager::s_Instance;

EnemyManager& EnemyManager::Get()
{
	return s_Instance;
}

void EnemyManager::InitializeEnemy()
{
	s_Instance.EnemyCount++;
}

void EnemyManager::EnemyDestroyed()
{
	s_Instance.EnemyCount--;
	s_Instance.OnEnemyDestroyed.Broadcast();
}

int EnemyManager::GetEnemyCount()
{
	return s_Instance.EnemyCount;
}
