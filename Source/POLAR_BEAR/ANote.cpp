﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ANote.h"


// Sets default values
AANote::AANote()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AANote::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AANote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AANote::Signal()
{
	IIA_intractable::Signal();
	
}

