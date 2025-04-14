// Fill out your copyright notice in the Description page of Project Settings.


#include "Traps.h"


// Sets default values
ATraps::ATraps()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATraps::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATraps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



