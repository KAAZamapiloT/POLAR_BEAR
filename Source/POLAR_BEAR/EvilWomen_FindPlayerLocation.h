// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EvilWomen_FindPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UEvilWomen_FindPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UEvilWomen_FindPlayerLocation(const FObjectInitializer& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Behavior")
	float SearchRadius=200.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Behavior")
	bool bSearchRandom=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Behavior")
	class AActor*AttackedActor;

	//FVector Location=AttackedActor->GetActorLocation();
};
