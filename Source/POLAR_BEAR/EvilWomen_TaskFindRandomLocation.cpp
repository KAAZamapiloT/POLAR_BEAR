// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskFindRandomLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UEvilWomen_TaskFindRandomLocation::UEvilWomen_TaskFindRandomLocation()
{
	NodeName=TEXT("FindRandomLocation");
	BlackboardKey.AddVectorFilter(this,GET_MEMBER_NAME_CHECKED(UEvilWomen_TaskFindRandomLocation,BlackboardKey));
}

EBTNodeResult::Type UEvilWomen_TaskFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	FNavLocation Location{};

	// GET AI PAWN
	AAIController*AiController=OwnerComp.GetAIOwner();

const APawn*AiPawn=AiController->GetPawn();

	const FVector Origin=AiPawn->GetActorLocation();

	//GRABBING THE NAVIGATION SYSTEM
	const UNavigationSystemV1*NavSystem{UNavigationSystemV1::GetCurrent(GetWorld())};


	if (NavSystem&&NavSystem->GetRandomPointInNavigableRadius(Origin,fSearchRadius,Location))
	{
		AiController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName,Location.Location);
	}

	// SIGNAL THAT TASK FINISHED WITH SUCESS

	FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UEvilWomen_TaskFindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector : %s"), *BlackboardKey.SelectedKeyName.ToString());
}
