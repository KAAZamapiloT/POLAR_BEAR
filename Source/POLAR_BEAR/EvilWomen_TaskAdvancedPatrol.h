// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_TaskAdvancedPatrol.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomen_TaskAdvancedPatrol : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	public:
	UEvilWomen_TaskAdvancedPatrol();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	FBlackboardKeySelector FArrayIndex;
	UPROPERTY(EditAnywhere,Category="AI")
	FVector Playerl;
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	float AcceptanceRadius;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	FBlackboardKeySelector FArrayKey;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	FBlackboardKeySelector FVectorKey;

};
