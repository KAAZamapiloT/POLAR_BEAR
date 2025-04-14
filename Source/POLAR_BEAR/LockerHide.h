// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"IA_intractable.h"
#include"IA_Hideable.h"
#include "LockerHide.generated.h"


class UStaticMeshComponent;
class UBoxComponent;
UCLASS()
class POLAR_BEAR_API ALockerHide : public AActor,public IIA_Hideable,public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALockerHide();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	UBoxComponent* BoxComp;
};
