// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/FPSAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


AFPSAIController::AFPSAIController()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>("Blackboard Component");
	check(Blackboard);

	BehaviourTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("Behaviour Tree Component");
	check(BehaviourTreeComponent);
}
