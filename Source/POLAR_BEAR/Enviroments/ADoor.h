// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ADoor.generated.h"
class UStaticMeshComponent;
class UBoxComponent;
class USoundCue;
class UAudioComponent;
UCLASS()
class POLAR_BEAR_API AADoor : public AActor
{
	GENERATED_BODY()
public:
	//UPROPERTY(BlueprintReadWrite)
	// UItem RequiredKey;
	UPROPERTY(BlueprintReadWrite)
	UBoxComponent*CollisionComponent;
	
	UPROPERTY(BlueprintReadWrite)
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
};
