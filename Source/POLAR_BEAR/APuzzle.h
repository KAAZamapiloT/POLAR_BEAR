// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADoor.h"
#include "GameFramework/Actor.h"
#include "APuzzle.generated.h"


class AADoor;

UENUM(BlueprintType)
enum class EPuzzleType : uint8
{
	Logic,
	Enviroment,
	Sequence,Combination,Computer
};

UCLASS()
class POLAR_BEAR_API AAPuzzle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAPuzzle();
private:
	bool bIsCompleted=false;
	uint8 Difficulty=0;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	EPuzzleType PuzzleType;
	UPROPERTY(EditAnywhere)
	AADoor* LinkedDoor;
	//TO DO ->USER WIDGET

UFUNCTION(BlueprintCallable)
	void Solve(FString Solution);

	UFUNCTION(BlueprintCallable)
	bool bIsComplete();

	UFUNCTION(BlueprintCallable)
	void OnComplete();
};
