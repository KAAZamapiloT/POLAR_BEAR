// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemsBase.h"

//#include "NavigationSystemTypes.h"
#include "Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"

// Sets default values
AItemsBase::AItemsBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	CollisionBox=CreateDefaultSubobject<UBoxComponent>(TEXT("BOX Collider"));
    CollisionBox->SetupAttachment(ItemMesh);
}

// Called when the game starts or when spawned
void AItemsBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemsBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

