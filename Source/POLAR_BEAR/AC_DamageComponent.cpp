// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_DamageComponent.h"


// Sets default values for this component's properties
UAC_DamageComponent::UAC_DamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_DamageComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAC_DamageComponent::TakeDamage()
{
}


// Called every frame
void UAC_DamageComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

