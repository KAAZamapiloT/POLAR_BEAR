// Fill out your copyright notice in the Description page of Project Settings.


#include "Bear_Base.h"


// Sets default values
ABear_Base::ABear_Base()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  
}

// Called when the game starts or when spawned
void ABear_Base::BeginPlay()
{
	Super::BeginPlay();
		
}

void ABear_Base::Damage(float DamageAmount)
{
	IIA_Damageable::Damage(DamageAmount);
}

void ABear_Base::healerDamage(float DamageAmount)
{
	IIA_Damageable::healerDamage(DamageAmount);
}

void ABear_Base::DamageNullification(float DamageAmount)
{
	IIA_Damageable::DamageNullification(DamageAmount);
}

void ABear_Base::overtimeDamage(float DamageAmount, float duration)
{
	IIA_Damageable::overtimeDamage(DamageAmount, duration);
}

bool ABear_Base::IsDead()
{
	return IIA_Damageable::IsDead();
}

bool ABear_Base::IsDamageable()
{
	return IIA_Damageable::IsDamageable();
}

double ABear_Base::ElementalPunch(FString element, double damage)
{
	return IIA_Damageable::ElementalPunch(element, damage);
}

// Called every frame
void ABear_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABear_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

