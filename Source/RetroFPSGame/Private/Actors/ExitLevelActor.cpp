// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ExitLevelActor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Player/FPSCharacter.h"
#include "Player/FPSController.h"

AExitLevelActor::AExitLevelActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AExitLevelActor::ExitLevel(AActor* PlayerActor)
{
	if (AFPSCharacter* Player = Cast<AFPSCharacter>(PlayerActor))
	{
		if(AFPSController* PC = Cast<AFPSController>(Player->GetController()))
		{
			UKismetSystemLibrary::QuitGame(GetWorld(), PC, EQuitPreference::Quit, true);
		}
	}
}

