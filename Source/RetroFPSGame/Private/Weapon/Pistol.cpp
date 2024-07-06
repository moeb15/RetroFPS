// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Pistol.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"

void APistol::InitializeWeapon_Implementation()
{
	WeaponFlipbook->SetFlipbook(Idle_Flipbook);
	WeaponFlipbook->SetHiddenInGame(false);
}
