// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_FindPlayerLocation.h"

#include "AICEvilWomen.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UEvilWomen_FindPlayerLocation::UEvilWomen_FindPlayerLocation(const FObjectInitializer& ObjectInitializer):
UBTTask_BlackboardBase{ObjectInitializer}
{
	NodeName = "EvilWomen_FindPlyerLocation";
}

EBTNodeResult::Type UEvilWomen_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//GET PLAYER CHARACTER
	if (auto* const Player =UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
         // GETTING PLAYER LOCATION
		auto const PlayerLocation=Player->GetActorLocation();
       
		if (bSearchRandom)
		{
			FNavLocation Location;
			// GETTING RANDOM LOCATION AND CREATING RANDOM POINTS 
			if (auto*const NavSys=UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				//TRY TO GET RANDOM LOCATION NEAR LAYER
				if (NavSys->GetRandomPointInNavigableRadius(PlayerLocation,SearchRadius,Location))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),Location.Location);
				}
			}
			//	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),PlayerLocation);
			//AAIController* AIController = OwnerComp.GetAIOwner();
			//if (AIController)
			//{
			//	AIController->MoveToLocation(PlayerLocation);
			//}**//
			
		
			FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}else{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),PlayerLocation);
			///
			/*OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),PlayerLocation);
			AAIController* AIController = OwnerComp.GetAIOwner();
			if (AIController)
			{
				AIController->MoveToLocation(PlayerLocation);
			}
			*/
			FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
		
	}
	
	return EBTNodeResult::Failed;
}
