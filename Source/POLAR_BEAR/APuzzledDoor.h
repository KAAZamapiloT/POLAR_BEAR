// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsBase.h"
#include "APuzzledDoor.generated.h"

class USoundBase;
UCLASS()
class POLAR_BEAR_API AAPuzzledDoor : public AItemsBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAPuzzledDoor();
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Puzzle")
	FString DoorCode;
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Puzzle")
	USoundBase* UnlockSound;
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Puzzle")
	USoundBase* PuzzleFailed;
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Puzzle")
	USoundBase* PuzzledSuccess;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Puzzle")
	USoundBase* LockSound;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Locks")
	bool bIsOpen;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Locks")
	bool bIsLocked;
};
