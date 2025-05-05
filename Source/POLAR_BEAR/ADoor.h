// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "IA_intractable.h"
#include "ADoor.generated.h"
class AAPuzzle;
class UStaticMeshComponent;
class UBoxComponent;
class USoundBase;
class UAudioComponent;
class AAKey;
UENUM(BlueprintType)
enum class EDoorType : uint8
{
	EDT_Normal UMETA(DisplayName = "Normal"),
	EDT_Final UMETA(DisplayName = "Final"),
	EDT_Special UMETA(DisplayName = "Special")
};

UCLASS(Blueprintable, BlueprintType)
class POLAR_BEAR_API AADoor : public AActor ,public IIA_intractable
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	class AAKey* RequiredKey;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UBoxComponent*CollisionComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UStaticMeshComponent*DoorMesh;

	
	
// sound for doors
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	UAudioComponent*AudioComponent;
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	USoundBase*OpenSound=nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	USoundBase*CloseSound=nullptr;
	UPROPERTY(BlueprintReadWrite,Category="Sounds")
	USoundBase*LockSound=nullptr;
    UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Puzzle")
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
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sectors")
	int Sector=0;
	UFUNCTION(BlueprintCallable,Blueprintable,category="Motion")
	bool Open();
	UFUNCTION(BlueprintCallable,Blueprintable,category="Motion")
	bool Close();
	UFUNCTION(BlueprintCallable,Blueprintable,category="Motion")
	bool Unlock();
	UFUNCTION(BlueprintCallable,Blueprintable)
	bool IsLocked();
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool bIsLocked=false;
    UPROPERTY(BlueprintReadWrite)
	EDoorType DoorType=EDoorType::EDT_Normal;
	// TO DO -> ADD INPUT U ITEM AS OVERRIDE
	
	UFUNCTION(BlueprintCallable,BlueprintCallable)
	void Signal() override;
	UPROPERTY(BlueprintReadWrite)
	ACharacter*OverlappedCharacter=nullptr;
    void OverlapEvent();
	UFUNCTION(BlueprintCallable,BlueprintCallable)
	void DoorOpen(FString KeyName,FString KeyType);// CASTING IN BLUEPRINTS AND CHECKING IT AGANIS T PLAYER CLASS INVENTORY FO KEY 
	
    void RevCast() override;
	
};
