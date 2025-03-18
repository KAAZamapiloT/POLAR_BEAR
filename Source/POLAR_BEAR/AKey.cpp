// Fill out your copyright notice in the Description page of Project Settings.


#include "AKey.h"

#include "FileCache.h"


// Sets default values
AAKey::AAKey()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAKey::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AAKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

