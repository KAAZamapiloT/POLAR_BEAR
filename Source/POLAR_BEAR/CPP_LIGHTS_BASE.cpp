// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_LIGHTS_BASE.h"


// Sets default values
ACPP_LIGHTS_BASE::ACPP_LIGHTS_BASE()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_LIGHTS_BASE::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_LIGHTS_BASE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

