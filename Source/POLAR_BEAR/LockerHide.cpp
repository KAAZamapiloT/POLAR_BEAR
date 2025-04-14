// Fill out your copyright notice in the Description page of Project Settings.


#include "LockerHide.h"

#include "Components/BoxComponent.h"


// Sets default values
ALockerHide::ALockerHide()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	MeshComp=CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	BoxComp=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void ALockerHide::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALockerHide::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

