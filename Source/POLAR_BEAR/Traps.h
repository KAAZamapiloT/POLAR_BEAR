// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <rapidjson/internal/meta.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"IA_intractable.h"
#include "Traps.generated.h"

UENUM(Blueprintable)
enum class ETrapType : uint8
{
SlowDown,
	Blur,
	Death
};

UCLASS()
class POLAR_BEAR_API ATraps : public AActor,public IIA_intractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATraps();
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Traps")
	ETrapType TrapType = ETrapType::SlowDown;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    UFUNCTION(BlueprintCallable,Blueprintable,Category="Traps")
	void Signal() override;
	UFUNCTION(BlueprintCallable,BlueprintCallable,Category="Traps")
	void RevCast() override;
};
