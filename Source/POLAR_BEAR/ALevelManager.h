// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADoor.h"
#include "EvilWomen.h"
#include "GameFramework/Actor.h"
#include "ALevelManager.generated.h"

UCLASS()
class POLAR_BEAR_API AALevelManager : public AActor 
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AALevelManager();
	UPROPERTY(EditAnywhere,Category="Level")      
int CurrentLevel;

	UPROPERTY(EditAnywhere,Category="Level")
	TArray<AADoor*> Doors;

	UPROPERTY(EditAnywhere,Category="Level")
	TArray<AAPuzzle*> Puzzles;

	UPROPERTY(EditAnywhere,Category="Level")
	AEvilWomen* EvilWomen;

	UPROPERTY(EditAnywhere,Category="Level")
	AADoor* FinalDoor;
	void PLaceItem();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
