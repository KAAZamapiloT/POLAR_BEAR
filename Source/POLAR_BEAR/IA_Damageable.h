// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IA_Damageable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UIA_Damageable : public UInterface
{
	GENERATED_BODY()
 

	
};

/**
 * 
 */
class POLAR_BEAR_API IIA_Damageable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Damage(float DamageAmount){};
	virtual void healerDamage(float DamageAmount) {}
	virtual void DamageNullification(float DamageAmount) {}
	virtual void overtimeDamage(float DamageAmount,float duration) {}
	virtual bool IsDamageable() { return true; }
	virtual bool IsDead(){return false;}
	virtual double ElementalPunch(FString element,double damage) {return 0;}
};
