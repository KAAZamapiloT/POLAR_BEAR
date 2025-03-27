// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BT_ServiceChangeSpeed.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UBT_ServiceChangeSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()

	public:
  UBT_ServiceChangeSpeed();
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	float Speed=600.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	float MinSpeed=250.f;
};
