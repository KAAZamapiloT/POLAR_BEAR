// Fill out your copyright notice in the Description page of Project Settings.


#include "AHidingSpot.h"

#include "POLAR_BEARCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAHidingSpot::AAHidingSpot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpotBox=CreateDefaultSubobject<UBoxComponent>(TEXT("SpotBox"));
	SpotBox->SetupAttachment(GetRootComponent());
	SpotMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpotMesh"));
	SpotMesh->SetupAttachment(SpotBox);
	SpotBox->SetGenerateOverlapEvents(true);
	SpotBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SpotBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	SpotBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AAHidingSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAHidingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAHidingSpot::Hide()
{
	IIA_Hideable::Hide();
	bIsActive=true;
	UE_LOG(LogTemp, Display, TEXT("AAHidingSpot -> Hide"));
}

void AAHidingSpot::Unhide()
{
	IIA_Hideable::Unhide();
	bIsActive=false;
	UE_LOG(LogTemp, Display, TEXT("AAHidingSpot -> Unhide"));
}

void AAHidingSpot::Signal()
{
	IIA_intractable::Signal();
	UE_LOG(LogTemp, Display, TEXT("AAHidingSpot -> signal"));
}

void AAHidingSpot::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor&&OtherActor!=this)
	{
		APOLAR_BEARCharacter*MyCharacter=Cast<APOLAR_BEARCharacter>(OtherActor);
		if (MyCharacter)
		{
			// would like to call a function that toggles state between hide and unhide
			UE_LOG(LogTemp, Display, TEXT("AAHidingSpot::OnOverlapBegin"));
		}
	}
}

void AAHidingSpot::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor&&OtherActor!=this)
	{
		APOLAR_BEARCharacter*MyCharacter=Cast<APOLAR_BEARCharacter>(OtherActor);
		if (MyCharacter)
		{
			//  would like build a functionality after end overlap
			UE_LOG(LogTemp, Display, TEXT("AAHidingSpot::OnOverlapEnd"));
		}
	}
}

