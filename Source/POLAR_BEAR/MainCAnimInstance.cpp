// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCAnimInstance.h"
#include "POLAR_BEARCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include"Kismet/KismetMathLibrary.h"
void UMainCAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	PolarCharacter= Cast<APOLAR_BEARCharacter>(TryGetPawnOwner());
	if (PolarCharacter)
	{
		PolarMove=PolarCharacter->GetCharacterMovement();
	}
}

void UMainCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (PolarMove)
	{
		
		GroundSpeed= UKismetMathLibrary::VSizeXY(PolarMove->Velocity);
	}
}
