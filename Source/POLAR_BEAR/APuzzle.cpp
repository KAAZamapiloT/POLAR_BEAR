// Fill out your copyright notice in the Description page of Project Settings.


#include "APuzzle.h"


// Sets default values
AAPuzzle::AAPuzzle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAPuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAPuzzle::Solve(FString Solution)
{
}

bool AAPuzzle::bIsComplete()
{
	return bIsCompleted;
}

void AAPuzzle::OnComplete()
{
}


