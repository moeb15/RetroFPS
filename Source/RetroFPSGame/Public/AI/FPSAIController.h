// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FPSAIController.generated.h"


class UBehaviorTreeComponent;
/**
 * 
 */
UCLASS()
class RETROFPSGAME_API AFPSAIController : public AAIController
{
	GENERATED_BODY()

public:
	AFPSAIController();

protected:
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviourTreeComponent;
};
