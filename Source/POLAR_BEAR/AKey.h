// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsBase.h"
#include "AKey.generated.h"

UENUM(BlueprintType)
enum class EKeyType : uint8
{
	EKT_Normal UMETA(DisplayName = "Normal"),
	EKT_Master UMETA(DisplayName = "MASTER"),
	EKT_Escape UMETA(DisplayName = "ESCAPE"),
};
class USoundCue;
UCLASS()
class POLAR_BEAR_API AAKey : public AItemsBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAKey();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    ItemType  isKey=ItemType::Key;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Key")
	USoundCue* sound;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
