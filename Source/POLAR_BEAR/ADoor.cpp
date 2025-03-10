// Fill out your copyright notice in the Description page of Project Settings.


#include "ADoor.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include"Sound/SoundCue.h"
#include"Components/AudioComponent.h"
#include"POLAR_BEARCharacter.h"
// Sets default values
AADoor::AADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BOX COLLIDER"));
	DoorMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DOOR MESH"));
	AudioComponent=CreateDefaultSubobject<UAudioComponent>(TEXT("AUDIO"));
	CollisionComponent->SetupAttachment(DoorMesh);
	
}

// Called when the game starts or when spawned
void AADoor::BeginPlay()
{
	Super::BeginPlay();
	
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
void AADoor::signal()
{
	IIA_intractable::signal();
	if(bIsLocked)
	{
		Unlock();
	}else if (bIsOpen)
	{
		Close();
	}else
	{
		Open();
	}
}



