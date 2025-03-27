// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskIncrementPathIndex.h"

#include "AICEvilWomen.h"
#include "EvilWomen.h"
#include "PatrolPath.h"

UEvilWomen_TaskIncrementPathIndex::UEvilWomen_TaskIncrementPathIndex(FObjectInitializer const& ObjectInitializer):
UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName="EvilWomen_TaskIncrementPathIndex";
}

EBTNodeResult::Type UEvilWomen_TaskIncrementPathIndex::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
//TRY GETTING AI CONTROLLER
if (auto*const cont=Cast<AAICEvilWomen>(Comp.GetAIOwner()))
{
//TRY AND GET EVIL WOMEN
	if (auto*const EvilWomen=Cast<AEvilWomen>(cont->GetPawn()))
	{
		//GETTING BLACKBOARD
		if (auto*const bc=Comp.GetBlackboardComponent())
		{
			//GET NO OF PATROL POINTS AND MIN AND MAX INDICES
			int const NoOfPoints=EvilWomen->GetPatrolPath()->num();
			int MinPoints=0;
			int MaxPoints=NoOfPoints-1;

			auto  Index=bc->GetValueAsInt(GetSelectedBlackboardKey());
			//CHANGE DIRECTION IF WE ARE AT FIRST OR LAST INDEX
			if (bIsBiDirectional)
			{
				if (Index>MaxPoints&&Direction==EDirectionType::Forward)
				{
					Direction=EDirectionType::BackWard;
				}else if (Index<=0&&Direction==EDirectionType::BackWard)
				{
					Direction=EDirectionType::Forward;
				}
			}
			//WRITE NEW VALUE OF INDEX TO BLACKBOARD
			bc->SetValueAsInt(GetSelectedBlackboardKey(),(Direction==EDirectionType::Forward?++Index:--Index)%NoOfPoints);
			//FINISH WITH SUCCESS
			FinishLatentTask(Comp,EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}

	
}



	
	return EBTNodeResult::Failed;
}
