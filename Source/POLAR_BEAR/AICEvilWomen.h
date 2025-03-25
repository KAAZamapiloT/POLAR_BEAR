// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "IA_Damageable.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense.h"

#include "AICEvilWomen.generated.h"

class UAISenseConfig;
class UAIPerceptionComponent;
class UBehaviorTreeComponent;

UCLASS()
class POLAR_BEAR_API AAICEvilWomen : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAICEvilWomen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void OnPossess(APawn* InPawn) override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	TObjectPtr<UBlackboardComponent> BlackboardComponent;
	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,Category="AI",meta=(AllowPrivateAccess=true))
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
	UPROPERTY(EditInstanceOnly,BlueprintReadOnly,Category="AI",meta=(AllowPrivateAccess=true))
	TObjectPtr<UBehaviorTree> BehaviorTree;
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="AI")
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="AI")
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	void OnTargetDetected(AActor* InTarget,FAIStimulus Stimulus);
};

inline void AAICEvilWomen::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
	FString Sense;

	// Compare with known Sense IDs
	if (Stimulus.Type == UAISense_Sight::StaticClass()->GetDefaultObject<UAISense>()->GetSenseID())
	{
		Sense = "Sight";
	}
	else if (Stimulus.Type == UAISense_Hearing::StaticClass()->GetDefaultObject<UAISense>()->GetSenseID())
	{
		Sense = "Hearing";
	}
	else
	{
		Sense = "Unknown Sense";
	}

	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Warning, TEXT("Detected %s using %s"), *Actor->GetName(), *Sense);
		BlackboardComponent->SetValueAsObject("Target", Actor);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Lost %s with %s"), *Actor->GetName(), *Sense);
		BlackboardComponent->ClearValue("Target");
	}
}
