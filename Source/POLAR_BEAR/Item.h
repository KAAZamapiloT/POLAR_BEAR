// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"


class UTexture;
class UStaticMesh;
class UBoxComponent;
UENUM()
enum ItemType
{
	Key,
	Document,
	Consumable
};
UCLASS()
class POLAR_BEAR_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();
protected:
	UPROPERTY(BlueprintReadWrite)
	FName ItemName;
	UPROPERTY(BlueprintReadWrite)
	ItemType Item;
	UPROPERTY(BlueprintReadWrite)
	FText ItemDescription;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
UPROPERTY(BlueprintReadWrite)
	bool bIsUsable;
	//TO DO : FINDING APPROPRIATE TEXXTURES UPROPERTY(BlueprintReadWrite)
	//UTexture*ItemIcon;
	UPROPERTY(BlueprintReadWrite)
    UStaticMesh*ItemMesh;
	UPROPERTY(BlueprintReadWrite)
	UBoxComponent*BoxCollision;
	
};
