// Copyright Epic Games, Inc. All Rights Reserved.

#include "POLAR_BEARGameMode.h"
#include "POLAR_BEARCharacter.h"
#include "UObject/ConstructorHelpers.h"

APOLAR_BEARGameMode::APOLAR_BEARGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
