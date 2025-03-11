// Fill out your copyright notice in the Description page of Project Settings.


#include "AHidingSpot.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAHidingSpot::AAHidingSpot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpotBox=CreateDefaultSubobject<UBoxComponent>(TEXT("SpotBox"));
	SpotBox->SetupAttachment(GetRootComponent());
	SpotMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpotMesh"));
	SpotMesh->SetupAttachment(SpotBox);
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

void AAHidingSpot::Hide()
{
	IIA_Hideable::Hide();
	UE_LOG(LogTemp, Display, TEXT("AAHidingSpot -> Hide"));
}

void AAHidingSpot::Unhide()
{
	IIA_Hideable::Unhide();
	UE_LOG(LogTemp, Display, TEXT("AAHidingSpot -> Unhide"));
}

void AAHidingSpot::signal()
{
	IIA_intractable::signal();
	UE_LOG(LogTemp, Display, TEXT("AAHidingSpot -> signal"));
}

