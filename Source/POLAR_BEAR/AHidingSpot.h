﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IA_Hideable.h"
#include"IA_intractable.h"
#include "AHidingSpot.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class USoundCue;
class UStaticMesh;

UCLASS()
class POLAR_BEAR_API AAHidingSpot : public AActor,public IIA_Hideable,public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAHidingSpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spot")
	UStaticMeshComponent* SpotMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spot")
	USoundCue* SpotSound;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spot")
	UBoxComponent* SpotBox;
	
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spot")
	bool bIsUnsafe;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spot")
	bool bIsActive;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spot")
	bool bIsQuickTimeable;
	
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Hide() override;

	UFUNCTION(BlueprintCallable)
	void Unhide() override;
	UFUNCTION(BlueprintCallable)
	void signal() override;
};
