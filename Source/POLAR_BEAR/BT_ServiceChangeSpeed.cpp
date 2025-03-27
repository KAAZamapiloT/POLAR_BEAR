// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_ServiceChangeSpeed.h"

#include "AIController.h"
#include "EvilWomen.h"
#include "GameFramework/CharacterMovementComponent.h"

UBT_ServiceChangeSpeed::UBT_ServiceChangeSpeed()
{
	bNotifyBecomeRelevant = true;
	NodeName=TEXT("BT_ServiceChangeSpeed");
	
}

void UBT_ServiceChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	if (auto*const cont=OwnerComp.GetAIOwner())
	{
		if (auto*const EvilWomen=Cast<AEvilWomen>(cont->GetPawn()))
		{
			EvilWomen->GetCharacterMovement()->MaxWalkSpeed=MinSpeed;
		}
	}
}
