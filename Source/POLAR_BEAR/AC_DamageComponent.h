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

USTRUCT(BlueprintType)           //THIS DAMAGE INFO IS CREATED FOR A PARTICULAR ATTACK
struct FDamageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageType Damage_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageReaction Damage_Reaction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanDodge;
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
};
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class POLAR_BEAR_API UAC_DamageComponent : public UActorComponent
{
	GENERATED_BODY()
	struct FHealthInfo Health={
    100,
		200,
		100,
		70,
		50,
		100
	};
	
public:
	// Sets default values for this component's properties
	UAC_DamageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    virtual void TakeDamage(double Amount) ;
	// CAN MAKE IT FIXED AMOUNT SO THAT GAME STAYS SIMPLER 
	virtual void IncreseStamina	();
	virtual void DecreseStamina	();
	//REGENERATION PLAYER MIGHT REGENERATE AFTER TAKING DAMAGE FROM ENEMY
	virtual void IncreaseHealth	();


	//  HEARTBEAT FUNCTIONS -> HEARBEAT IS DEPENDEND ON EMENY LOCATION AND DISTANCE FROM PLAYER SO IT MIGHT BE COMPLEX
	virtual void ChangeHeartBeat();
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
