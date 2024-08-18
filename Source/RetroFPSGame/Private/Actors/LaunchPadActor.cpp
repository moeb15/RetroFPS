// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/LaunchPadActor.h"
#include "Player/FPSCharacter.h"
#include "Components/BoxComponent.h"


ALaunchPadActor::ALaunchPadActor()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	SetRootComponent(CollisionBox);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Launch Pad Mesh");
	StaticMesh->SetupAttachment(GetRootComponent());

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPadActor::LaunchActor);
}


void ALaunchPadActor::LaunchActor(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,	
	bool bFromSweep,
	const FHitResult& SweepResult) 
{
	if (AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(OtherActor))
	{
		const FVector LaunchPadUpVec = StaticMesh->GetUpVector();
		PlayerCharacter->LaunchCharacter(LaunchPadUpVec * LaunchSpeed, true, true);
	}
}

