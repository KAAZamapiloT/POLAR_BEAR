// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class POLAR_BEAR_API UMainCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	UPROPERTY(BlueprintReadWrite,Category="Movement")
	float GroundSpeed;
     UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	class APOLAR_BEARCharacter*PolarCharacter;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	class UCharacterMovementComponent*PolarMove;
};
