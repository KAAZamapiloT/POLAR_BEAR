// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsBase.h"
#include "Components/ActorComponent.h"
#include "AInventoryComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class POLAR_BEAR_API UAInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	TArray<AActor*> Inventory;
    UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetInventory(TArray<AActor*> NewInventory);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool bContains(AItemsBase* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(AItemsBase* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(AItemsBase* item);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
