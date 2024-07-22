// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Pistol.h"
#include "PaperFlipbook.h"
#include "Components/PointLightComponent.h"
#include "PaperFlipbookComponent.h"

APistol::APistol()
{
	WeaponFlipbook->OnFinishedPlaying.AddDynamic(this, &APistol::StopFiring);
	SetCanFire(true);
}

void APistol::InitializeWeapon_Implementation()
{
	WeaponFlipbook->SetFlipbook(Idle_Flipbook);
	WeaponFlipbook->SetHiddenInGame(false);
	WeaponDraw();
}

void APistol::SwapFlipbook_Implementation()
{
	WeaponFlipbook->SetFlipbook(Fire_Flipbook);
	WeaponFlipbook->SetHiddenInGame(false);
	WeaponFlipbook->Play();
}

void APistol::StopFiring() {
	GetLight()->SetHiddenInGame(true);
	WeaponFlipbook->SetFlipbook(Idle_Flipbook);
}