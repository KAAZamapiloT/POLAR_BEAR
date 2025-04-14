// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsBase.h"
#include "IA_intractable.h"
#include "ANote.generated.h"

UCLASS()
class POLAR_BEAR_API AANote : public AItemsBase , public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AANote();
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Note;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Signal() override;
};
