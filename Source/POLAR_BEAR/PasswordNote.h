// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IA_intractable.h"
#include "ItemsBase.h"
#include "PasswordNote.generated.h"

UCLASS()
class POLAR_BEAR_API APasswordNote : public AItemsBase,public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APasswordNote();
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Note")
	FString Note;
	UFUNCTION(BlueprintCallable, Category = "Note")
	void Signal() override;

	void RevCast() override;
};
