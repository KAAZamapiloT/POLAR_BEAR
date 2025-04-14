// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomenTask_ResetTimer.h"

#include "AICEvilWomen.h"

UEvilWomenTask_ResetTimer::UEvilWomenTask_ResetTimer(FObjectInitializer const& ObjectInitializer)
{
	NodeName="SET VALUE";
}

EBTNodeResult::Type UEvilWomenTask_ResetTimer::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{

	if (auto c=Cast<AAICEvilWomen>(Comp.GetAIOwner()))
	{
		if (auto*bc=c->GetBlackboardComponent())
		{

			bc->SetValueAsInt(GetSelectedBlackboardKey(),val);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
