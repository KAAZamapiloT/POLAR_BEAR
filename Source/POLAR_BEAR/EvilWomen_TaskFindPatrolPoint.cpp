// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskFindPatrolPoint.h"

#include "AICEvilWomen.h"
#include "EvilWomen.h"
#include "PatrolPath.h"

EBTNodeResult::Type UEvilWomen_TaskFindPatrolPoint::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{

	//ATTEMPT TO GET EVIL WOMEN CONTROLLER
 if (auto* cont=Cast<AAICEvilWomen>(Comp.GetAIOwner()))
 {

 	//GETTING BLACKBOARD COMPONENT
 	if (auto* bc=Comp.GetBlackboardComponent())
 	{
 		//GET CURRENT PATROL PATH INDEX

       auto const index=bc->GetValueAsInt(GetSelectedBlackboardKey());

 		//GET EVIL WOMEN
 		if (auto*EvilWomen=Cast<AEvilWomen>(cont->GetPawn()))
 		{
 			//GET CURRENT PATROL PATH VECTOR FROM EVIL WOMEN
 			// SINCE PATROL POINTS ARE RELATIVE WE NEED TO CONVERT THEM TO GLOBAL
 			auto const Point=EvilWomen->GetPatrolPath()->GetPatrolPoint(index);

 			//CONVERT LOCAL VECTOR TO LOCAL POINT
 			
 			auto const GlobalPoint=EvilWomen->GetPatrolPath()->GetActorTransform().TransformPosition(Point);

 			bc->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName,GlobalPoint);
 			FinishLatentTask(Comp,EBTNodeResult::Succeeded);
 			return EBTNodeResult::Succeeded;
 		}
 		
 	}

 	
 }





	
	return EBTNodeResult::Failed;
}

UEvilWomen_TaskFindPatrolPoint::UEvilWomen_TaskFindPatrolPoint(FObjectInitializer const& ObjectInitializer)
{

	NodeName = "EvilWomen_TaskFindPatrolPoint";
}
