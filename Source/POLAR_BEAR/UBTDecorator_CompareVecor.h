// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_ForceSuccess.h"
#include "UBTDecorator_CompareVecor.generated.h"

/**
 *
 * THIS DECORATOR COMPARE VECTOR MAGNITUDE WITH FLOAT AND RETURNS A BOOLEAN VALUE
 */
UCLASS()
class POLAR_BEAR_API UUBTDecorator_CompareVecor : public UBTDecorator_ForceSuccess
{
	GENERATED_BODY()
public:
	explicit UUBTDecorator_CompareVecor();
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
