// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

UCLASS()
class POLAR_BEAR_API APatrolPath : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APatrolPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(MakeEditWidget=true))
	TArray<FVector> Actors;
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="AI")
	FVector GetPatrolPoint(const int index) const;
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="AI")
	int num() const;
};

inline FVector APatrolPath::GetPatrolPoint(const int index) const
{
	return Actors[index];
}

inline int APatrolPath::num() const
{
	return Actors.Num();
}
