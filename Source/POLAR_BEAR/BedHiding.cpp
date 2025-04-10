﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "BedHiding.h"

#include "Camera/CameraComponent.h"


// Sets default values
ABedHiding::ABedHiding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComp=CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpotMesh);
}

// Called when the game starts or when spawned
void ABedHiding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABedHiding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

