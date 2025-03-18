// Fill out your copyright notice in the Description page of Project Settings.


#include "ADoor.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include"Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"
#include"Sound/SoundBase.h"
#include"Components/AudioComponent.h"

#include"POLAR_BEARCharacter.h"
#include "AKey.h"
#include "SQCapture.h"
#include "Engine/OverlapResult.h"
// Sets default values
AADoor::AADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BOX COLLIDER"));
	DoorMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DOOR MESH"));
	AudioComponent=CreateDefaultSubobject<UAudioComponent>(TEXT("AUDIO"));
	CollisionComponent->SetupAttachment(DoorMesh);
	AudioComponent->SetupAttachment(CollisionComponent);
}

// Called when the game starts or when spawned
void AADoor::BeginPlay()
{
	Super::BeginPlay();
	AudioComponent->Play();
}

// Called every frame
void AADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AADoor::Open()
{
	return true;
}

bool AADoor::Close()
{
	return false;
}

bool AADoor::Unlock()
{
	return true;
}

bool AADoor::IsLocked()
{
	return bIsLocked;
}


// THIS FUNCTION WILL TELL US ALL ABOUT WHAT TO DO WITH DOOR BASED ON ITS CONDITION	 IF ITS LOCKED TRY TO UNLOCK AND PLAY UNLOCK SOUND
void AADoor::Signal()
{
	
	IIA_intractable::Signal();
	if(bIsLocked)
	{
	/*
	 * A DOOR CHECK AND AN OVERLAP EVENT REACTION CAN BE ADDED HERE
	 * WHERE A FUNCTION WOULD CHECK IN PLAYERS INVENTORY WHETHER PLAYER CONTAINS A KEY AND OR NOT
	 * PRIORITY OF KEY -> MASTER KEY > NORMAL KEY > ESCAPE KEY  
	 */

		RevCast();
		UE_LOG(LogTemp,Error,TEXT("AADoor::UNlocked -> unlock called due to lack of implementation"));
	}else if (bIsOpen)
	{
		Close();
	
		UE_LOG(LogTemp,Error,TEXT("AADoor::IsClosed"));
	}else
	{
		Open();
	
		UE_LOG(LogTemp,Error,TEXT("AADoor::IsOpen"));
	}
}

void AADoor::OverlapEvent()
{
	
}

void AADoor::DoorOpen(FString KeyName,FString KeyType)
{
	if (KeyName == KeyMap)
	{
		bIsLocked = false;
	}else if (KeyType=="Master"&&DoorType==EDoorType::EDT_Normal)
	{
		bIsLocked = false;
	}
}
// IF DOOR CAN BE UNLOCKED THIS FUNCTION WILL UNLOCK THE DOOR
void AADoor::RevCast()
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
	UE_LOG(LogTemp,Display,TEXT("AADoor::RevCast"));

if(bHit)
{
	for (auto& Overlap : Overlaps)
	{
		AActor*OverlappedActor=Overlap.GetActor();


		if(OverlappedActor)
		{

			APOLAR_BEARCharacter*MyCharacter=Cast<APOLAR_BEARCharacter>(OverlappedActor);
			if(MyCharacter)
			{
				bIsLocked=!MyCharacter->bCheckKeyString(KeyMap);
				if (DoorType==EDoorType::EDT_Normal&&MyCharacter->bCheckMasterString())
				{
					bIsLocked=false;
				}
				else if (MyCharacter->KInventory->KeyNames.Contains(KeyMap))
				{
					bIsLocked=false;
				}
			}
		}
	}
}

	
}









