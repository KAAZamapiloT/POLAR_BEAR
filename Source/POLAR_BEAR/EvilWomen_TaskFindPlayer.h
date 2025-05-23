﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"

#include "EvilWomen_TaskFindPlayer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class POLAR_BEAR_API UEvilWomen_TaskFindPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UEvilWomen_TaskFindPlayer();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;

	UFUNCTION(BlueprintCallable)
	void FindPlayer();


	

	
};
