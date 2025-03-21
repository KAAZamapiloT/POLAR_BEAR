// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "IA_Damageable.h"
#include "KeysInventory.h"
#include "Elements/Common/TypedElementCommonTypes.h"

#include "POLAR_BEARCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UAnimMontage;
class USoundBase;
class UAInventoryComponent;
DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);



UENUM(BlueprintType)
enum class EState:uint8
{
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_NotAttacking UMETA(DisplayName = "Not Attacking"),
};

UCLASS(config=Game)
class APOLAR_BEARCharacter : public ACharacter,public IIA_Damageable
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
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//UInputAction* HidesAction;
public:
	APOLAR_BEARCharacter();
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Audio")	
USoundBase*HitSound;
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
/*warp jump -> trying to fix aimations during character jumps*/
	void WrapJump();
	void WrapStopJump();
/* ALL THESE ACTIONS AHAVE SAME BASE HAVE A ENVIROMENTAL QUERY AND THEN CHECK WHAT IS POSSIBLE*/
	void Intract();
	void Attack();
	void HideAction();
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
UPROPERTY(BlueprintReadWrite)
	bool bIsIntracting=false;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Hiding")
	bool bIsHidden=false;
    void JustDie();
    void Damage(float DamageAmount) override;
    bool bIsDead = false;
	int DeathCount=0;
	void  ResetDamage();
	bool bCheckKeyString(FString KeyString);
	bool bCheckMasterString();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	class UKeysInventory *KInventory;
	UFUNCTION(BlueprintCallable, Category = "Hiding")
	void Hide();
	UFUNCTION(BlueprintCallable, Category = "Hiding")
	void UnHide();
	UFUNCTION(Blueprintable,BlueprintCallable ,Category = "Hiding")
	void ToggleHideState();
};


// IF PLAYER RESPAWNING ABILTY CAN GET CREATED 
inline void APOLAR_BEARCharacter::ResetDamage()  
{
	bIsDead=false;
}


// SINCE ATTACKING WOULD HAVE NO EFFECT ON ENEMY ATTACKING WOULD FUNCTION AS INTRACTION RATHER THAN ATTACKING


