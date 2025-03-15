// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_DamageComponent.h"

#include "IA_Damageable.h"
#include"Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values for this component's properties
UAC_DamageComponent::UAC_DamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_DamageComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAC_DamageComponent::TakeDamage(double Amount)
{
		Health.CurrentHealth-=Amount;
}

void UAC_DamageComponent::IncreseStamina(double Amount)
{
   if (Health.Stamina+Amount<=Health.MaxStamina)
   {
	   Health.Stamina+=Amount;
   }else
   {
	   Health.Stamina=Health.MaxStamina;
   }
}

void UAC_DamageComponent::DecreseStamina(double Amount)
{
		Health.Stamina-=Amount;

}

void UAC_DamageComponent::IncreaseHealth(double Amount)
{
	if (Health.CurrentHealth+Amount<=Health.MaxHealth)
	{
		Health.CurrentHealth+=Health.MaxHealth;
	}else
	{
		Health.CurrentHealth=Health.MaxHealth;
	}
	
	
}

void UAC_DamageComponent::IncreseHeartbeat(double Amount)
{
	Health.HeartBeat+=Amount;
}

void UAC_DamageComponent::DecreseHeartbeat(double Amount)
{
	if (Health.HeartBeat-Amount>=Health.MinHeartBeat)
	{
		Health.HeartBeat-=Amount;
	}else
	{
		Health.HeartBeat=Health.MinHeartBeat;
	}
}


bool UAC_DamageComponent::FbIsDead()
{
	if (Health.CurrentHealth<=0)
	{
		return true;
	}
	return false;
}

bool UAC_DamageComponent::FbIsHavingHeartAttack(double Threashold)
{
	if (Health.HeartBeat>Threashold)
	{
		return true;
	}
	return false;
}




// Called every frame
void UAC_DamageComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

