// Fill out your copyright notice in the Description page of Project Settings.


#include "UBTDecorator_CompareVecor.h"

#include "AICEvilWomen.h"

UUBTDecorator_CompareVecor::UUBTDecorator_CompareVecor()
{
	NodeName = "UUBTDecorator_CompareVecor";
}

bool UUBTDecorator_CompareVecor::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
bool result = false;
	
	if (auto cont=Cast<AAICEvilWomen>(OwnerComp.GetAIOwner()))
	{
		if (auto bc=cont->GetBlackboardComponent())
		{
         FVector a=bc->GetValueAsVector("PlayerLocation");
			float b=bc->GetValueAsFloat("AcceptanceRadius");
			FVector c=bc->GetValueAsVector("PatrolPathPoint");
			result=abs(FVector(a.X,a.Y,0).Size()-FVector(c.X,c.Y,0).Size())>b;
		}
	}
	
	return result;
}
