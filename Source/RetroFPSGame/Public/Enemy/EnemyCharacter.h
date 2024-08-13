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

protected:
	virtual void PossessedBy(AController* NewController) override;

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
