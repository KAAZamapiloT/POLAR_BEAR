// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_TaskFindRandomLocation.generated.h"

/**
 *
 BT TASK FOR FINDING A RANDOM LOCATION ON A NAVMESH
 */
UCLASS(Blueprintable)
class POLAR_BEAR_API UEvilWomen_TaskFindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UEvilWomen_TaskFindRandomLocation();
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Search",meta=(AllowPrivateAccess=true))
	float fSearchRadius=500;
};
