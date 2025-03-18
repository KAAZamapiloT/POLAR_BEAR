// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AKey.h"
#include "Components/ActorComponent.h"
#include "KeysInventory.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),BlueprintType)
class POLAR_BEAR_API UKeysInventory : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UKeysInventory();
     UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FString> KeyNames;
    
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
