// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskFindPlayer.h"
#include"AICEvilWomen.h"
#include "POLAR_BEARCharacter.h"
#include "Perception/AISense.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UEvilWomen_TaskFindPlayer::UEvilWomen_TaskFindPlayer()
{
	NodeName = "FindPlayer";
	
}

EBTNodeResult::Type UEvilWomen_TaskFindPlayer::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	AAIController* AIController = Comp.GetAIOwner();
	APawn* Pawn = AIController->GetPawn();
	
	UBlackboardComponent* BlackboardComp = AIController->GetBlackboardComponent();
	AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject("Target"));
	if (!AIController||!BlackboardComp)
	{
		UE_LOG(LogTemp,Error,TEXT("WHERE IS AI CONTROLLER AND BLACKBOARD"))
		return EBTNodeResult::Failed;
	}
	if (Target)
	{
		AIController->MoveToActor(Target, 100.0f);
		UE_LOG(LogTemp, Warning, TEXT("%s is target found"), *Target->GetName());
		return EBTNodeResult::Succeeded;
		
	}
    return EBTNodeResult::Failed;
}

void UEvilWomen_TaskFindPlayer::FindPlayer()
{
	
}
