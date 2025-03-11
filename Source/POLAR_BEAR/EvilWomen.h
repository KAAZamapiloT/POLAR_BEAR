// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICEvilWomen.h"

#include "EvilWomen.generated.h"
class UAnimMontage;


UENUM(BlueprintType)
enum class EactionState:uint8
{
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_NotAttacking UMETA(DisplayName = "Not Attacking"),
};

UCLASS()
class POLAR_BEAR_API AEvilWomen : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEvilWomen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<UAnimMontage*>Montages;
    EactionState AttackState=EactionState::EAS_NotAttacking;
	void PlayMontages();
    UFUNCTION(BlueprintCallable)
	void AttackEnd()
	{
		AttackState=EactionState::EAS_NotAttacking;
	}
   UFUNCTION(BlueprintCallable)
	void AttackTrace();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
	void Attack();
};

inline void AEvilWomen::Attack()
{
if (AttackState==EactionState::EAS_NotAttacking)
{
	PlayMontages();
	AttackTrace();
	AttackState=EactionState::EAS_Attacking;
}
	
}



