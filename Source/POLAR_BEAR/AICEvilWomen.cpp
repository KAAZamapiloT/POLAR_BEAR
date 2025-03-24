// Fill out your copyright notice in the Description page of Project Settings.


#include "AICEvilWomen.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"


// Sets default values
AAICEvilWomen::AAICEvilWomen()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BlackboardComponent=CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Component"));
	BehaviorTreeComponent=CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	AIPerceptionComponent=CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    
	SightConfig->SightRadius = 500.0f;
	SightConfig->LoseSightRadius = 600.0f;
	SightConfig->PeripheralVisionAngleDegrees = 60.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->SetMaxAge(4.0f);
	AIPerceptionComponent->ConfigureSense(*SightConfig);
	AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
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
}

// Called every frame
void AAICEvilWomen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

