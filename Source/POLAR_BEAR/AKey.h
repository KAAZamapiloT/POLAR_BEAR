// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsBase.h"
#include"IA_intractable.h"
#include "AKey.generated.h"

UENUM(BlueprintType)
enum class EKeyType : uint8
{
	EKT_Normal UMETA(DisplayName = "Normal"),
	EKT_Master UMETA(DisplayName = "MASTER"),
	EKT_Escape UMETA(DisplayName = "ESCAPE"),
};

class UBoxComponent;
class USoundCue;
UCLASS(Blueprintable,BlueprintType)
class POLAR_BEAR_API AAKey : public AItemsBase,public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAKey();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
    ItemType  Type=ItemType::Key;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Key")
	EKeyType KeyType=EKeyType::EKT_Normal;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Key")
	USoundCue* sound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Key")
	FString Code;

	
    UFUNCTION(BlueprintCallable,Category="Key")
	void Signal() override;
	void RevCast() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
