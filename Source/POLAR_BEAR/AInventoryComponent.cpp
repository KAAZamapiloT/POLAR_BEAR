// Fill out your copyright notice in the Description page of Project Settings.


#include "AInventoryComponent.h"


// Sets default values for this component's properties
UAInventoryComponent::UAInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UAInventoryComponent::SetInventory(TArray<AActor*> NewInventory)
{
	Inventory = NewInventory;
}

bool UAInventoryComponent::bContains(AItemsBase* Item)
{
	return Inventory.Contains(Item);
}

void UAInventoryComponent::RemoveItem(AItemsBase* Item)
{
	Inventory.Remove(Item);
}

void UAInventoryComponent::AddItem(AItemsBase* item)
{
	Inventory.Add(item);
}

// Called every frame
void UAInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

