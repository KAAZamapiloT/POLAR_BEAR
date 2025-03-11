// Fill out your copyright notice in the Description page of Project Settings.


#include "AHidingSpot.h"


// Sets default values
AAHidingSpot::AAHidingSpot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAHidingSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAHidingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

