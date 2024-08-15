// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "AbilitySystemComponent.h"
#include "Player/FPSCharacter.h"
#include "PaperFlipbook.h"
#include "AI/FPSAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
	Enemy = CreateDefaultSubobject<UPaperFlipbookComponent>("Enemy Flipbook");
	Enemy->SetupAttachment(GetRootComponent());
	
	Enemy->OnFinishedPlaying.AddDynamic(this, &AEnemyCharacter::KillEnemy);

	Enemy->SetFlipbook(EnenyDefaultFlipbook);
	//Enemy->SetLooping(true);

	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OrientTowardsPlayer();
	Death();
}

FHitResult AEnemyCharacter::FireWeapon_Implementation()
{
	Enemy->SetFlipbook(EnemyFireWeapon);
	Enemy->SetLooping(false);
	Enemy->Play();

	//const APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	const FVector StartPos = GetActorLocation();
	const FVector EndPos = StartPos + GetActorRightVector() * 4000.f;

	FHitResult HitRes;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(
		HitRes,
		StartPos,
		EndPos,
		ECC_Visibility,
		CollisionParams
	);

	return HitRes;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FPSAIController = Cast<AFPSAIController>(Controller);

	//FPSAIController->Possess(this);
	FPSAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviourTree->BlackboardAsset);
	FPSAIController->RunBehaviorTree(BehaviourTree);
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
	if (Enemy->GetFlipbook() == EnemyDeath)
	{
		Destroy();
	}
	else
	{
		Enemy->SetFlipbook(EnenyDefaultFlipbook);
		Enemy->SetLooping(true);
		Enemy->Play();
	}
}
