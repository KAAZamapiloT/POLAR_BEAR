// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_FindPlyerLocation.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomen_FindPlyerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()


	explicit UEvilWomen_FindPlyerLocation(const FObjectInitializer& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
