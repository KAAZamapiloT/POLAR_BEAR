﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "AICEvilWomen.h"

#include "POLAR_BEARCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include  "PatrolPath.h"
#include "Perception/AISenseConfig_Hearing.h"

// Sets default values
AAICEvilWomen::AAICEvilWomen()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BlackboardComponent=CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Component"));
	BehaviorTreeComponent=CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	//AIPerceptionComponent=CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));
	//SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
SetupPerceptionSystem();
	
}

// Called when the game starts or when spawned
void AAICEvilWomen::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(BehaviorTree.Get()))
	{
		RunBehaviorTree(BehaviorTree.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree.Get());  // giving refrence to behavior  tree
		UE_LOG(LogTemp,Warning,TEXT("behavior terre was valod"));
	}
	
}

void AAICEvilWomen::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(IsValid(BlackboardComponent.Get())&&IsValid(BehaviorTree.Get()))
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
	}
	RunBehaviorTree(BehaviorTree);
}

// Called every frame
void AAICEvilWomen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAICEvilWomen::SetupPerceptionSystem()
{
      SightConfig=CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
	if (HearingConfig)
	{
		HearingConfig->HearingRange=3000.0f;
		
		HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
		HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
		HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
		HearingConfig->SetMaxAge(20.f);
		HearingConfig->SetStartsEnabled(true);
		GetPerceptionComponent()->ConfigureSense(*HearingConfig);
	}
	if (SightConfig)
	{
		
        

		SightConfig->SightRadius = 800.0f;
		SightConfig->LoseSightRadius = SightConfig->SightRadius+25.f;
		SightConfig->PeripheralVisionAngleDegrees = 75.0f;
		SightConfig->SetMaxAge(5.f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation=550.f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
 
		
        GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this,&AAICEvilWomen::AAICEvilWomen::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
		
	}
	
}

void AAICEvilWomen::OnTargetDetected(AActor* InTarget, FAIStimulus Stimulus)
{
	if (auto*const ch=Cast<APOLAR_BEARCharacter>(InTarget))
	{
		BlackboardComponent->SetValueAsBool("IsSeeingPlayer",Stimulus.WasSuccessfullySensed());
		
	}
	else if (Stimulus.Type == UAISense::GetSenseID<UAISense_Hearing>())
	{
		UE_LOG(LogTemp,Warning,TEXT("HEARING Loop was entered"));
		if (Stimulus.WasSuccessfullySensed())
		{
			BlackboardComponent->SetValueAsBool("IsHearingPlayer", true);
			BlackboardComponent->SetValueAsVector("LastHeardLocation", Stimulus.StimulusLocation);
			UE_LOG(LogTemp,Warning,TEXT("HEARING WAS SENSED"));
		}
	}
}

