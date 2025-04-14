// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICEvilWomen.h"

#include "EvilWomen.generated.h"
class UAnimMontage;

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
UENUM(BlueprintType)
enum class EactionState:uint8
{
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_NotAttacking UMETA(DisplayName = "Not Attacking"),
};


USTRUCT(BlueprintType)
struct FPatrolRoute
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Patrol")
	TArray<AActor*> PatrolPoints;
};
UCLASS()
class POLAR_BEAR_API AEvilWomen : public ACharacter ,public IIA_Damageable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEvilWomen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	UAIPerceptionComponent* PerceptionComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<UAnimMontage*>Montages;
    EactionState AttackState=EactionState::EAS_NotAttacking;
	void PlayMontages();
	
    UFUNCTION(BlueprintCallable)
	void AttackEnd()
	{
		AttackState=EactionState::EAS_NotAttacking;
	}
   UFUNCTION(BlueprintCallable)
	void AttackTrace();
	UFUNCTION(BlueprintCallable,Blueprintable,Category="AI")
	void Intract();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	UAISenseConfig_Sight* SightConfig;

	// EVIL WOMEN CONTROLLER
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	class AAICEvilWomen* EvilWomenController;
    /*
     *
     * NAVIGATION COMPONENTSS
     */

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI",meta=(AllowPrivateAccess=true))
	class APatrolPath* PatrolPath;


	UFUNCTION(BlueprintCallable,category="AI")
	APatrolPath* GetPatrolPath()const ;
	//CURRENT PATROL TARGET	
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI_Navigation")
	AActor*PatrolTarget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	TArray<APatrolPath*> PatrolActors;

    //ADVANCED PATROLLING (OPTIONAL MAY NOT BE IN FINAL)

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	//TArray<AActor*> CurrentPatrolArray;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	int32 CurrentPatrolIndex=0;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	//TArray<FPatrolRoute> PatrolArray;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	//TArray<APatrolPath*> CurrentPatrolActors;
	//UFUNCTION(BlueprintCallable,Blueprintable,Category="AI")
	//FPatrolRoute GetClosestPatrolRoute(AActor*PlayerActor)const;
	
	// SOMETHINGS RELATED TO PUZZLE SYSTEM
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	TSubclassOf<UAIPerceptionComponent> PerceptionComponentClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	TSubclassOf<UAISenseConfig_Sight> SightConfigClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	bool bCanOpenDoor=false;
	UFUNCTION(BlueprintCallable,Blueprintable, Category="AI")
	void OpenDoor();
	UFUNCTION(BlueprintCallable)
	void Attack();
	
};




inline void AEvilWomen::Attack()
{
if (AttackState==EactionState::EAS_NotAttacking)
{
	PlayMontages();
	AttackTrace();
	AttackState=EactionState::EAS_Attacking;
}
	
}



