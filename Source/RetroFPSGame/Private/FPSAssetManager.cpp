// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAssetManager.h"
#include "FPSGameplayTags.h"

UFPSAssetManager& UFPSAssetManager::Get() {
	check(GEngine);
	return *Cast<UFPSAssetManager>(GEngine->AssetManager);
}

void UFPSAssetManager::StartInitialLoading() {
	Super::StartInitialLoading();

	FRetroFPSGameplayTags::InitializeNativeGameplayTags();
}