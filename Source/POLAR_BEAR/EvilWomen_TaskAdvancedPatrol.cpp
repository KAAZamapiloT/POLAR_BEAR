// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskAdvancedPatrol.h"

#include "AICEvilWomen.h"
#include "EvilWomen.h"
#include "PatrolPath.h"

UEvilWomen_TaskAdvancedPatrol::UEvilWomen_TaskAdvancedPatrol()

{
	NodeName=TEXT("ADVANCED_PATROL");
	AcceptanceRadius=800.f;
	Playerl=FVector(0,0,0);
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
                   
              	FVector PlayerLocation=bc->GetValueAsVector("PlayerLocation");

              	FVector PatrolLocation=bc->GetValueAsVector("PatrolPathPoint");

              	float DistanceToPlayer = FVector::Dist(PlayerLocation, EvilWomen->GetActorLocation());

              	if (DistanceToPlayer>bc->GetValueAsFloat("AcceptanceRadius"))
              	{
                    int min=0;
              		auto LL=EvilWomen->PatrolActors;
              		if(LL[0]==nullptr){return EBTNodeResult::Failed;}
                      for (int i=1;i<EvilWomen->PatrolActors.Num();++i)
                      {
	                     if (FVector::DistXY(PlayerLocation,LL[i-1][0].GetActorTransform().GetLocation())>FVector::DistXY(PatrolLocation,LL[i][0].GetActorTransform().GetLocation()))
	                     {
		                     min=i;
	                     	UE_LOG(LogTemp, Display, TEXT("PlayerLocation: %s | Patrol Actor Location: %s"),
	*PlayerLocation.ToString(), *LL[i - 1][0].GetActorTransform().GetLocation().ToString());

	                     	UE_LOG(LogTemp,Display,TEXT("Patrol Actor location CHanged"));
	                     } 
                      }
                     
                    UE_LOG(LogTemp,Warning,TEXT("ArrayPatrol Works"))
                    EvilWomen->PatrolPath=EvilWomen->PatrolActors[min];
              		EvilWomen->CurrentPatrolIndex=min;
              		bc->SetValueAsVector(GetSelectedBlackboardKey(),EvilWomen->PatrolPath[0].GetActorLocation());
              	}
              	
              	
              }
     		return EBTNodeResult::Succeeded;
     	}


     	
     }


	
	return EBTNodeResult::Failed;
}
