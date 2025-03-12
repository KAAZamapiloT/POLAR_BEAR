// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "IA_intractable.h"
#include "ADoor.generated.h"
class AAPuzzle;
class UStaticMeshComponent;
class UBoxComponent;
class USoundCue;
class UAudioComponent;

UENUM(BlueprintType)
enum class EDoorType : uint8
{
	EDT_Normal UMETA(DisplayName = "Normal"),
	EDT_Final UMETA(DisplayName = "Final"),
	EDT_Special UMETA(DisplayName = "Special")
};

UCLASS()
class POLAR_BEAR_API AADoor : public AActor ,public IIA_intractable
{
	GENERATED_BODY()
public:
	//UPROPERTY(BlueprintReadWrite)
	// UItem RequiredKey;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UBoxComponent*CollisionComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UStaticMeshComponent*DoorMesh;
	
	
// sound for doors
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	UAudioComponent*AudioComponent;
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	USoundCue*OpenSound=nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	USoundCue*CloseSound=nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	USoundCue*LockSound=nullptr;
    UPROPERTY(BlueprintReadWrite,Category="Puzzle")
	FString KeyMap;
	UPROPERTY(BlueprintReadWrite)
	bool bIsOpen=true;
public:
	// Sets default values for this actor's properties 
	AADoor();
     
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable,Blueprintable)
	bool Open();
	UFUNCTION(BlueprintCallable,Blueprintable)
	bool Close();
	UFUNCTION(BlueprintCallable,Blueprintable)
	bool Unlock();
	UFUNCTION(BlueprintCallable,Blueprintable)
	bool IsLocked();
	UPROPERTY(BlueprintReadWrite)
	bool bIsLocked=false;
    UPROPERTY(BlueprintReadWrite)
	EDoorType DoorType=EDoorType::EDT_Normal;
	// TO DO -> ADD INPUT U ITEM AS OVERRIDE
	UFUNCTION(BlueprintCallable,BlueprintCallable)
	void signal() override;
    
	UFUNCTION(BlueprintCallable,BlueprintCallable)
	void DoorOpen(FString Key,FString KeyType);
	
};
