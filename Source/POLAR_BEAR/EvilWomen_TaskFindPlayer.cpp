// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen_TaskFindPlayer.h"
#include"AICEvilWomen.h"
#include "POLAR_BEARCharacter.h"
#include "Perception/AISense.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UEvilWomen_TaskFindPlayer::UEvilWomen_TaskFindPlayer()
{
	NodeName = "Attack Player";
	AttackCooldown = 1.0f;       
	LastAttackTime = -AttackCooldown;
}

EBTNodeResult::Type UEvilWomen_TaskFindPlayer::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{

    return EBTNodeResult::Failed;
}

void UEvilWomen_TaskFindPlayer::FindPlayer()
{
	
}
