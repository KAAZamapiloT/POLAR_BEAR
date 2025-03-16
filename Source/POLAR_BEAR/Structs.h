// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/Blueprint.h"
#include "Structs.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EEffects: uint8
{
	NoDamage,          // DAMAGE IN NULLIFIED
	UnlimitedStamina,  // NO STAMINA REDUCTION 
	SpedUp,            // 
	MentallyTough      // NO SANITY DROP 
	
};

UENUM(BlueprintType)
enum class EDamageTypes : uint8
{
	None            UMETA(DisplayName = "None"),
	Melee           UMETA(DisplayName = "Melee"),
	RangedGun       UMETA(DisplayName = "Ranged (Gun)"),
	RangedThrown    UMETA(DisplayName = "Ranged (Thrown)"),
	Overtime        UMETA(DisplayName = "Over Time"),
	Fire            UMETA(DisplayName = "Fire"),
	Water           UMETA(DisplayName = "Water"),
	Ice             UMETA(DisplayName = "Ice"),
	Poison          UMETA(DisplayName = "Poison"),
	Electric        UMETA(DisplayName = "Electric"),
	Psychic         UMETA(DisplayName = "Psychic"),
	Emotional       UMETA(DisplayName = "Emotional"),
	Cosmic          UMETA(DisplayName = "Cosmic"),
	Explosive       UMETA(DisplayName = "Explosive")
};
UENUM(BlueprintType)
enum class EDamageReactions : uint8
{

	None        UMETA(DisplayName = "None"),
   Stagger      UMETA(DisplayName = "Stagger"),
   Stun         UMETA(DisplayName = "Stun"),
   Fallback     UMETA(DisplayName = "Fall Back"),
   StunFallback UMETA(DisplayName = "Stun and Fall Back"),
   Burn         UMETA(DisplayName = "Burn"),
   Freeze       UMETA(DisplayName = "Freeze"),
   Shock        UMETA(DisplayName = "Shock"),
   Panic        UMETA(DisplayName = "Panic"),
   Depression   UMETA(DisplayName = "Depression")
};

USTRUCT(BlueprintType)           //THIS DAMAGE INFO IS CREATED FOR A PARTICULAR ATTACK
                                 //ENEMY CANT BE DAMAGED	
struct FDamageInfos
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageTypes DamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageReactions DamageReaction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double SanityReduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double StaggerReduction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeDodged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeStopped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeNullified;
};
USTRUCT(BlueprintType)
struct FHealthInfos
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Sanity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HeartBeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinHeartBeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStamina;
};
UCLASS()
class POLAR_BEAR_API UStructs : public UObject
{
	GENERATED_BODY()
};
