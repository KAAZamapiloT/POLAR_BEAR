// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_TaskChasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomen_TaskChasePlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UEvilWomen_TaskChasePlayer();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;
	
};
