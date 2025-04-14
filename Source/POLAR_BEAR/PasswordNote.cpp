// Fill out your copyright notice in the Description page of Project Settings.


#include "PasswordNote.h"


// Sets default values
APasswordNote::APasswordNote()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APasswordNote::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APasswordNote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APasswordNote::Signal()
{

RevCast();
	
	IIA_intractable::Signal();
}

void APasswordNote::RevCast()
{
	IIA_intractable::RevCast();
}

