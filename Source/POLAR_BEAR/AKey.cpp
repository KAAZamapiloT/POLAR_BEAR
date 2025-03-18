// Fill out your copyright notice in the Description page of Project Settings.


#include "AKey.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include"POLAR_BEARCharacter.h"
#include "FileCache.h"
#include "IDetailTreeNode.h"
#include "Engine/OverlapResult.h"


// Sets default values
AAKey::AAKey()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");
	//RootComponent = ItemMesh;
	//CollisionBox->SetupAttachment(ItemMesh);
	
}

// Called when the game starts or when spawned
void AAKey::BeginPlay()
{
	Super::BeginPlay();
	
}



void AAKey::Signal()
{
	IIA_intractable::Signal();
	// IF PLAYER INTRACTS WITH IT WE ARE GOING TO CAST IT TO PLAYER CHARACTER
	RevCast();

	
	
}

void AAKey::RevCast()
{
	IIA_intractable::RevCast();
	FVector SphereCenter = GetActorLocation();
	float SphereRadius = 500.f;

	// Array to store overlapping actors
	TArray<FOverlapResult> Overlaps;

	// Collision query params
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // Ignore self

	// Collision object types - here focusing on Pawns (Characters)
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_Pawn);

	bool bHit = GetWorld()->OverlapMultiByObjectType(
		Overlaps,
		SphereCenter,
		FQuat::Identity,
		ObjectQueryParams,
		FCollisionShape::MakeSphere(SphereRadius),
		Params
	);

	// Debug Sphere
	DrawDebugSphere(GetWorld(), SphereCenter, SphereRadius, 16, FColor::Cyan, false, 2.0f);
	UE_LOG(LogTemp,Display,TEXT("AAKey::RevCast"));

	if(bHit)
	{
		for (auto& Overlap : Overlaps)
		{
			AActor* OverlappedActor = Overlap.GetActor();



			if(OverlappedActor)
			{

				APOLAR_BEARCharacter*MyCharacter=Cast<APOLAR_BEARCharacter>(OverlappedActor);
				if(MyCharacter)
				{
					MyCharacter->bIsIntracting = true;
					MyCharacter->KInventory->KeyNames.Add(Code);
					ItemMesh->SetVisibility(false); // Make it invisible
					ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // Disable collision
					ItemMesh->SetActive(false); // Deactivate component logic (optional)
                    CollisionBox->SetVisibility(false);
					
					CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
					CollisionBox->SetActive(false);
				}
			}
		}
	}

	
}

// Called every frame
void AAKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

