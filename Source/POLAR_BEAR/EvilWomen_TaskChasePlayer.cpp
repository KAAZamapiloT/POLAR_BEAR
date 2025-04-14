// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskChasePlayer.h"

#include "AICEvilWomen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UEvilWomen_TaskChasePlayer::UEvilWomen_TaskChasePlayer()
{
	NodeName="ChasePlayer";
}

EBTNodeResult::Type UEvilWomen_TaskChasePlayer::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
   //	GET TARGET LOCATION FROM BLACKBOARD
	
    if (auto* const cont=Cast<AAICEvilWomen>(Comp.GetAIOwner()))
    {
    	auto const PlayerLocation=Comp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());
        Comp.GetBlackboardComponent()->SetValueAsBool("bChased",true);
    	UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont,PlayerLocation);
    	FinishLatentTask(Comp,EBTNodeResult::Succeeded);
    	return EBTNodeResult::Succeeded;
    }


	
	
	return EBTNodeResult::Failed;
}
