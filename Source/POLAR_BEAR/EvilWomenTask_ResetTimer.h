// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomenTask_ResetTimer.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomenTask_ResetTimer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	public:
	explicit UEvilWomenTask_ResetTimer(FObjectInitializer const&ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Behavior")
	int val=0;

};
