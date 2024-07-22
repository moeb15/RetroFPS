// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/FPSCharacterBase.h"
#include "EnemyCharacter.generated.h"

class UPaperFlipbookComponent;
class UPaperFlipbook;

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API AEnemyCharacter : public AFPSCharacterBase
{
	GENERATED_BODY()

public:
	AEnemyCharacter();
	virtual void Tick(float DeltaTime) override;

private:
	void OrientTowardsPlayer();
	void Death();

	UFUNCTION()
	void KillEnemy();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbookComponent> Enemy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbook> EnemyDeath;

};
