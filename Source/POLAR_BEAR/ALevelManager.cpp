// Fill out your copyright notice in the Description page of Project Settings.


#include "ALevelManager.h"


// Sets default values
AALevelManager::AALevelManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AALevelManager::PLaceItem()
{
}

// Called when the game starts or when spawned
void AALevelManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

