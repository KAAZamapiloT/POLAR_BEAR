// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskAdvancedPatrol.h"

#include "AICEvilWomen.h"
#include "EvilWomen.h"

UEvilWomen_TaskAdvancedPatrol::UEvilWomen_TaskAdvancedPatrol()

{
	NodeName=TEXT("ADVANCED_PATROL");
}

EBTNodeResult::Type UEvilWomen_TaskAdvancedPatrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    //GETTING AI CONTROLLER
     if (auto*const cont=Cast<AAICEvilWomen>(OwnerComp.GetAIOwner()))
     {
       //GETTING Evil Women
     	if (auto*const EvilWomen=Cast<AEvilWomen>(cont->GetPawn()))
     	{
            
     		
              if (auto*const bc=cont->GetBlackboardComponent())
              {
                   
              	
 
              	
              	
              }
     		return EBTNodeResult::Succeeded;
     	}


     	
     }


	
	return EBTNodeResult::Failed;
}
