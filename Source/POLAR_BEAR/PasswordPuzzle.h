// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"IA_intractable.h"
#include "PasswordPuzzle.generated.h"

UCLASS()
class POLAR_BEAR_API APasswordPuzzle : public AActor,public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APasswordPuzzle();
private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))
	FString RequiredCode;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsSolved=false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="RewardString")
	FString RewardString;

	UFUNCTION(BlueprintCallable,BlueprintCallable)
	void Signal() override;

	
};
