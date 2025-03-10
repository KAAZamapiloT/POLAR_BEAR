// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemsBase.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
UENUM(Blueprintable)
enum class ItemType:uint8
{
	Key,
	Document,
	Consumeable
};
UENUM(Blueprintable)
enum class ItemStatus:uint8
{
	Equipped,
	Unequipped,
	Used,
	Shine,
	Outline
};
UCLASS()
class POLAR_BEAR_API AItemsBase : public AActor
{
	GENERATED_BODY()

private:
	FName ItemName;
	FName ItemDescreption;
	UPROPERTY(BlueprintReadWrite,meta=(AllowPrivateAccess="true"))
	ItemType type;
	
public:	
	// Sets default values for this actor's properties
	AItemsBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent*ItemMesh;
	UPROPERTY(BlueprintReadWrite)
	UBoxComponent*CollisionBox;
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FName getName() const {return ItemName;}
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FName getDescription()const {return ItemDescreption;}
	UFUNCTION(BlueprintCallable)
	inline bool bIsKey() const {
		if (type==ItemType::Key)
	{
		return true;
	}
		return false;
	}
};
