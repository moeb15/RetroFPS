// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "AbilitySystemComponent.h"
#include "PaperFlipbook.h"

AEnemyCharacter::AEnemyCharacter()
{
	Enemy = CreateDefaultSubobject<UPaperFlipbookComponent>("Enemy Flipbook");
	Enemy->SetupAttachment(GetRootComponent());
	
	Enemy->OnFinishedPlaying.AddDynamic(this, &AEnemyCharacter::KillEnemy);
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OrientTowardsPlayer();
	Death();
}

void AEnemyCharacter::OrientTowardsPlayer()
{
	const APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	const FVector EnemyLoc = GetActorLocation();
	const FVector PlayerCameraLoc = CameraManager->GetCameraLocation();

	const FRotator Rot = UKismetMathLibrary::FindLookAtRotation(EnemyLoc, PlayerCameraLoc);
	const FRotator CurRot = GetActorRotation();
	SetActorRotation(FRotator(CurRot.Pitch, Rot.Yaw - 90.f, CurRot.Roll));
}

void AEnemyCharacter::Death()
{
	if (GetAttributeSet()->GetHealth() <= 0.f) {
		Enemy->SetFlipbook(EnemyDeath);
		Enemy->SetLooping(false);
	}
}

void AEnemyCharacter::KillEnemy()
{
	Destroy();
}
