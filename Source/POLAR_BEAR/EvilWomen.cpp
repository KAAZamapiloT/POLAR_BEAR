// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilWomen.h"


// Sets default values
AEvilWomen::AEvilWomen()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEvilWomen::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEvilWomen::PlayMontages()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	int32 r=FMath::RandRange(0,2);
	if (AnimInstance&&Montages[r])
	{
		AnimInstance->Montage_Play(Montages[r]);
		AnimInstance->Montage_JumpToSection("Default");
		
	}
}


void AEvilWomen::AttackTrace()
{
	FVector StartLocation=GetActorLocation();
	
	FVector EndLocation=StartLocation+400*GetActorForwardVector();
	FHitResult rHit;
	TArray<FHitResult> HitResults;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	bool bHit = GetWorld()->LineTraceMultiByChannel(HitResults, StartLocation, EndLocation, ECC_Visibility, CollisionParams);
	DrawDebugLine(GetWorld(),StartLocation,EndLocation,FColor::Green,false,1,0,5);
	if(ActorLineTraceSingle(rHit, StartLocation, EndLocation, ECC_WorldStatic, CollisionParams))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *rHit.GetComponent()->GetName()));
	}
	if (bHit)
	{
		for (auto& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (Hit.GetActor())  
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *Hit.GetActor()->GetName());
			}
			if (HitActor->Implements<UIA_Damageable>())
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit Actor Implemets interface: %s"), *Hit.GetActor()->GetName());
				IIA_Damageable* Damageable = Cast<IIA_Damageable>(HitActor);
				if (Damageable)
				{
					Damageable->Damage(100);  
					UE_LOG(LogTemp, Error, TEXT("Damage Is Called: %s"), *HitActor->GetName());
				}
			}
			// Draw debug sphere at each hit location
			DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 10.0f, 12, FColor::Red, false, 2.0f);
		}
	}
	
}

// Called every frame
void AEvilWomen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEvilWomen::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

