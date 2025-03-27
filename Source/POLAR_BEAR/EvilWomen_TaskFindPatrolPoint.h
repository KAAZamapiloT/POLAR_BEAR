// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_TaskFindPatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomen_TaskFindPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;
	explicit UEvilWomen_TaskFindPatrolPoint(FObjectInitializer const& ObjectInitializer);

private:
	UPROPERTY(EditAnywhere,Category="BlackBoard",meta=(AllowPrivateAccess=true))
	FBlackboardKeySelector PatrolPathVectorKey;
};
