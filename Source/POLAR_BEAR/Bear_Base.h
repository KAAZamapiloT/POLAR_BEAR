// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IA_Damageable.h"
#include "Bear_Base.generated.h"

UCLASS()
class POLAR_BEAR_API ABear_Base : public ACharacter,public IIA_Damageable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABear_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
  // functions implemented from interface
	
	virtual void Damage(float DamageAmount) override; // Damage amount done by bear
	
	virtual void healerDamage(float DamageAmount) override;
	virtual void DamageNullification(float DamageAmount) override;
	virtual void overtimeDamage(float DamageAmount, float duration) override;
	virtual bool IsDead() override;
	virtual bool bIsBlocked();
	virtual bool IsDamageable() override;
	virtual double ElementalPunch(FString element, double damage) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    bool bBlocked;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
