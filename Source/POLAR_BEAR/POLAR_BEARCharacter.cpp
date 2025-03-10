// Copyright Epic Games, Inc. All Rights Reserved.

#include "POLAR_BEARCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/EngineTypes.h"        // Core tracing and collision types.
#include "CollisionQueryParams.h"      // For customizing collision queries.
#include "DrawDebugHelpers.h"          // For visualizing traces (debugging).
#include "Engine/HitResult.h"          // For storing trace or hit data.
#include "Math/Vector.h"               // For FVector (positions, directions).
#include "Math/Quat.h"                 // For FQuat (rotations).
#include "Math/Transform.h"            // For FTransform (locations, rotations, scales).
#include "Math/UnrealMathUtility.h"    // For math utilities.
#include "PhysicsEngine/ShapeElem.h"   // For general collision shapes.
#include "CollisionShape.h"            // For FCollisionShape (e.g., sphere, box, capsule).
#include "IA_intractable.h"
#include "GameFramework/DamageType.h"  // For defining and applying damage.
#include "Kismet/GameplayStatics.h"    // For gameplay utilities (applying damage, spawning effects, etc.).
#include "InputActionValue.h"          // For Enhanced Input System (UE5-specific).
#include "GameFramework/InputSettings.h" // For standard input handling.
#include "Animation/AnimMontage.h"
DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// APOLAR_BEARCharacter

APOLAR_BEARCharacter::APOLAR_BEARCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void APOLAR_BEARCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void APOLAR_BEARCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APOLAR_BEARCharacter::WrapJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APOLAR_BEARCharacter::WrapStopJump);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APOLAR_BEARCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APOLAR_BEARCharacter::Look);
		//Sprinting
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &APOLAR_BEARCharacter::Sprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &APOLAR_BEARCharacter::StopSprint);
        EnhancedInputComponent->BindAction(WeakAttackAction,ETriggerEvent::Started,this,&APOLAR_BEARCharacter::Attack);
		EnhancedInputComponent->BindAction(Intraction,ETriggerEvent::Completed,this,&APOLAR_BEARCharacter::Intract);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void APOLAR_BEARCharacter::PlayMontage()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance&&AttackMontage)
	{
		AnimInstance->Montage_Play(AttackMontage);
		AnimInstance->Montage_JumpToSection("Default");
		UE_LOG(LogTemplateCharacter, Display, TEXT("Attacking ..."));
	}
}

void APOLAR_BEARCharacter::AttackEnd()
{
	AttackState=EState::EAS_NotAttacking;
}

void APOLAR_BEARCharacter::WrapJump()
{
	bInAir=true;
	ACharacter::Jump();
}

void APOLAR_BEARCharacter::WrapStopJump()
{
	
	ACharacter::StopJumping();
	bInAir=false;
}

void APOLAR_BEARCharacter::Intract()
{

	FVector StartLocation=GetActorLocation();
	
	FVector EndLocation=StartLocation+100*GetActorForwardVector();
	FHitResult rHit;
	TArray<FHitResult> HitResults;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	bool bHit = GetWorld()->LineTraceMultiByChannel(HitResults, StartLocation, EndLocation, ECC_Visibility, CollisionParams);
	DrawDebugLine(GetWorld(),StartLocation,EndLocation,FColor::Green,false,1,0,5);
	if(ActorLineTraceSingle(rHit, StartLocation, EndLocation, ECC_WorldStatic, CollisionParams))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *rHit.GetComponent()->GetName()));
	}
	if (bHit)
	{
		for (auto& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (Hit.GetActor())  // Ensure valid actor was hit
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *Hit.GetActor()->GetName());
			}
			if (HitActor->Implements<UIA_intractable>())
             {
             	UE_LOG(LogTemp, Warning, TEXT("Hit Actor Implemets interface: %s"), *Hit.GetActor()->GetName());
				// ✅ Correct Interface Cast
				IIA_intractable* Intractable = Cast<IIA_intractable>(HitActor);
				if (Intractable)
				{
					Intractable->signal();  // Call interface function
					UE_LOG(LogTemp, Error, TEXT("Signal Is Called: %s"), *HitActor->GetName());
				}
             }
			// Draw debug sphere at each hit location
			DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 10.0f, 12, FColor::Green, false, 2.0f);
		}
	}
	
}
// THIS FUNCTION WOULD BE USEFUL FOR EVIL WOMEN CLASS BECCAUSE THE EVIL WOMEN ALSO HAS TO ATTACK PLAYER
void APOLAR_BEARCharacter::Attack()
{
	if (AttackState==EState::EAS_NotAttacking&&bIsIntracting)
	{
		PlayMontage();
		Intract();
		AttackState=EState::EAS_Attacking;
	}

	
}


void APOLAR_BEARCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void APOLAR_BEARCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void APOLAR_BEARCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
}

void APOLAR_BEARCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
}


void APOLAR_BEARCharacter::weak_attack()
{
	TArray<FHitResult> HitResults;
	FVector Start=GetActorLocation();
	
}
