// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AHidingSpot.h"
#include "BedHiding.generated.h"

UCLASS()
class POLAR_BEAR_API ABedHiding : public AAHidingSpot
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABedHiding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
