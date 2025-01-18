// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_DamageComponent.generated.h"

// IMPORTANT VARIABLES FOR DAMAGE SYSTEM
UENUM(BlueprintType)
enum class EDamageType : uint8
{
	None UMETA(DisplayName = "None"),
	Melee UMETA(DisplayName = "Melee"),
	RangedGun UMETA(DisplayName = "Ranged (Gun)"),
	RangedThrown UMETA(DisplayName = "Ranged (Thrown)"),
	Overtime UMETA(DisplayName = "Over Time"),
	Fire UMETA(DisplayName = "Fire"),
	Water UMETA(DisplayName = "Water"),
	Ice UMETA(DisplayName = "Ice"),
	Poison UMETA(DisplayName = "Poison"),
	Electric UMETA(DisplayName = "Electric"),
	Psychic UMETA(DisplayName = "Psychic"),
	Emotional UMETA(DisplayName = "Emotional"),
	Cosmic UMETA(DisplayName = "Cosmic"),
	Explosive UMETA(DisplayName = "Explosive")
};
UENUM(BlueprintType)
enum class EDamageReaction : uint8
{
	None UMETA(DisplayName = "None"),
   Stagger UMETA(DisplayName = "Stagger"),
   Stun UMETA(DisplayName = "Stun"),
   Fallback UMETA(DisplayName = "Fall Back"),
   StunFallback UMETA(DisplayName = "Stun and Fall Back"),
   Burn UMETA(DisplayName = "Burn"),
   Freeze UMETA(DisplayName = "Freeze"),
   Shock UMETA(DisplayName = "Shock"),
   Panic UMETA(DisplayName = "Panic"),
   Depression UMETA(DisplayName = "Depression")
};

USTRUCT(BlueprintType)
struct FDamageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double HitsPerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageType Damage_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageReaction Damage_Reaction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanDodge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanIntereput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanNullify;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool StaggerDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool StunDamage;
	UPROPERTY(editAnywhere, BlueprintReadWrite)
	bool FallBackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool StunFallBackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BurnDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool FreezeDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShockDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PanicDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDepressed;
	
};
USTRUCT(BlueprintType)
struct FHealthInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double FlameResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double MaxFlameResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double DamageResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double MaxDamageResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Temprature;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double FreezeResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double ShockResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double PanicResistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double DepressionResistance;
	
};
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class POLAR_BEAR_API UAC_DamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAC_DamageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    virtual void TakeDamage() ;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
