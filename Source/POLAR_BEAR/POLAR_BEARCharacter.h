// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "AC_DamageComponent.h"
#include "POLAR_BEARCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UAnimMontage;
DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);



UENUM(BlueprintType)
enum class EState:uint8
{
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_NotAttacking UMETA(DisplayName = "Not Attacking"),
};

UCLASS(config=Game)
class APOLAR_BEARCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
    /**Sprint Input Acton */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* SprintAction;
    	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* WeakAttackAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* Intraction;
public:
	APOLAR_BEARCharacter();
	

protected:
/*
 *   CALLBACKS TO INPUT
 *   
 */
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
/** Called for sprinting characters*/		
   void Sprint();
/** Called for stopping Sprint*/
   void StopSprint();
/** Weak attack -> Faster -> Deals_less_Damage*/ 
void weak_attack();
	void WrapJump();
	void WrapStopJump();
	void Intract();
	void Attack();
protected:

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	/*  Animation Montages */
	UPROPERTY(EditDefaultsOnly,Category = "Montages")
	UAnimMontage* AttackMontage;
    UPROPERTY(BlueprintReadWrite,Category = "Montages",meta=(AllowPrivateAccess="true"))
    EState AttackState=EState::EAS_NotAttacking;
	void PlayMontage();
    UFUNCTION(BlueprintCallable)
	void AttackEnd();
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	UPROPERTY(BlueprintReadWrite)
	bool bInAir=false;
	
};



