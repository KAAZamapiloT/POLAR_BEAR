// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_DamageComponent.generated.h"

// IMPORTANT VARIABLES FOR DAMAGE SYSTEM
UENUM(BlueprintType)
enum class EEffect: uint8
{
	NoDamage,   // DAMAGE IN NULLIFIED
	UnlimitedStamina, // NO STAMINA REDUCTION 
	SpedUp,           // 
	MentallyTough    // NO SANITY DROP 
	
};

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
                                 //ENEMY CANT BE DAMAGED	
struct FDamageInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageType DamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageReaction DamageReaction;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStamina;
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
		100,
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
	virtual void IncreseStamina	(double Amount);
	virtual void DecreseStamina	(double Amount);
	//REGENERATION PLAYER MIGHT REGENERATE AFTER TAKING DAMAGE FROM ENEMY
	virtual void IncreaseHealth	(double Amount);


	//  HEARTBEAT FUNCTIONS -> HEARBEAT IS DEPENDEND ON EMENY LOCATION AND DISTANCE FROM PLAYER SO IT MIGHT BE COMPLEX
void IncreseHeartbeat(double Amount);

void DecreseHeartbeat(double Amount);

	// FUNCTION TO CHECK IF CHARACTER IS DEAD
	bool FbIsDead();    
	// FUCNTION TO CHECK FOR HEART ATTACK
	bool FbIsHavingHeartAttack(double ThreashHold);
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
