// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/FPSCharacterBase.h"
#include "EnemyCharacter.generated.h"

class UPaperFlipbookComponent;
class UPaperFlipbook;
class AFPSAIController;
class UBehaviorTree;
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
	virtual FHitResult FireWeapon_Implementation() override;
	virtual void Destroyed() override;
	virtual void Die() const override;

protected:
	virtual void BeginPlay() override;

private:
	void OrientTowardsPlayer();

	UFUNCTION()
	void KillEnemy();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbookComponent> Enemy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbook> EnenyDefaultFlipbook;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbook> EnemyFireWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enemy,
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPaperFlipbook> EnemyDeath;

	UPROPERTY(EditDefaultsOnly, Category = "AI",
		meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTree> BehaviourTree;

	UPROPERTY()
	TObjectPtr<AFPSAIController> FPSAIController;
};
