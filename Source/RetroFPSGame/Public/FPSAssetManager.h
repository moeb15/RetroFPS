// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FPSAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class RETROFPSGAME_API UFPSAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	static UFPSAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
