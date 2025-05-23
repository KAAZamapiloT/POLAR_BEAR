﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_TaskIncrementPathIndex.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomen_TaskIncrementPathIndex : public UBTTask_BlackboardBase
{
	GENERATED_BODY()


	public:
	explicit UEvilWomen_TaskIncrementPathIndex(FObjectInitializer const&ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;


	private:
	enum class EDirectionType{Forward,BackWard};

    EDirectionType Direction=EDirectionType::Forward;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	bool bIsBiDirectional = false;

  
	
	
};
