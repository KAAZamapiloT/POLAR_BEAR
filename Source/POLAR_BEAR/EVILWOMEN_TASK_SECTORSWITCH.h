// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EVILWOMEN_TASK_SECTORSWITCH.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEVILWOMEN_TASK_SECTORSWITCH : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	UEVILWOMEN_TASK_SECTORSWITCH();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent* OwnerComp, uint8* NodeMemory);
};
