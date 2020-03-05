// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
//version 2.0

#include "enemy_npc1_char.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "CW_SOWCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

//////////////////////////////////////////////////////////////////////////
// Aenemy_npc1_char

Aenemy_npc1_char::Aenemy_npc1_char()
{
	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Set the size of our collision capsule.
	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
	GetCapsuleComponent()->SetCapsuleRadius(40.0f);

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	CameraBoom->bAbsoluteRotation = true;
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->RelativeRotation = FRotator(0.0f, -90.0f, 0.0f);


	// Create an orthographic camera (no perspective) and attach it to the boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->OrthoWidth = 2048.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->bAbsoluteRotation = true;
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Configure character movement
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	// Note: This can cause a little floating when going up inclines; you can choose the tradeoff between better
	// behavior on the edge of a ledge versus inclines by setting this to true or false
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;

	// 	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarGear"));
	// 	TextComponent->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	// 	TextComponent->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	// 	TextComponent->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	// 	TextComponent->SetupAttachment(RootComponent);

	// Enable replication on the Sprite component so animations show up when networked
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;

	move_2_player = true;
	move_right = true;
	b_player_dash_enabled = false;

}

void Aenemy_npc1_char::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharPtr = Cast<ACW_SOWCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

//////////////////////////////////////////////////////////////////////////
// Animation

void Aenemy_npc1_char::UpdateAnimation_enemy_npc1_char()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

	// Are we moving or standing still?
	UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;
	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

void Aenemy_npc1_char::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	MoveRight_enemy_npc1_char(DeltaSeconds);

	UpdateCharacter_enemy_npc1_char();

	GetHit();

	HitPlayerCharacter();
}


//////////////////////////////////////////////////////////////////////////
// Input

void Aenemy_npc1_char::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Note: the 'Jump' action and the 'MoveRight_enemy_npc1_char' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight_enemy_npc1_char", this, &Aenemy_npc1_char::MoveRight_enemy_npc1_char);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &Aenemy_npc1_char::TouchStarted_enemy_npc1_char);
	PlayerInputComponent->BindTouch(IE_Released, this, &Aenemy_npc1_char::TouchStopped_enemy_npc1_char);
}


void Aenemy_npc1_char::GetHit()
{
	bool OnPlayerDash = PlayerCharPtr->DashAttackEnabled;
	if (OnPlayerDash == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("6. OnPlayerDash == true start"));
		FVector enemy_npc1_char_location = GetActorLocation();
		float enemy_npc1_char_x_location = enemy_npc1_char_location.X;

		FVector player_location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		float player_x_location = player_location.X;
		float player_char_hit_range = 1000.f;
		float player_hit_location_max = enemy_npc1_char_x_location + player_char_hit_range;
		float player_hit_location_min = enemy_npc1_char_x_location - player_char_hit_range;

		if (player_x_location >= player_hit_location_min && player_x_location <= player_hit_location_max)
		{
			UE_LOG(LogTemp, Warning, TEXT("7. destroy start"));
			bool bDestroyed = Destroy();
			if (bDestroyed)
			{
				UE_LOG(LogTemp, Warning, TEXT("9. destroy is true"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("10. destroy is false"));
			}
			UE_LOG(LogTemp, Warning, TEXT("8. destroy end"));
		}
		UE_LOG(LogTemp, Warning, TEXT("6. OnPlayerDash == true end"));
	}
}

void Aenemy_npc1_char::HitPlayerCharacter()
{
	FVector enemy_npc1_char_location = GetActorLocation();
	float enemy_npc1_char_x_location = enemy_npc1_char_location.X;

	FVector player_location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	float player_x_location = player_location.X;
	float enemy_npc1_hit_range = 900.f;
	float enemy_hit_location_max = player_x_location + enemy_npc1_hit_range;
	float enemy_hit_location_min = player_x_location - enemy_npc1_hit_range;

	if (enemy_npc1_char_x_location >= enemy_hit_location_min && enemy_npc1_char_x_location <= enemy_hit_location_max)
	{
		if (PlayerCharPtr)
		{
			UE_LOG(LogTemp, Warning, TEXT("1. hit casting start"));
			PlayerCharPtr->OnGetHit();
			UE_LOG(LogTemp, Warning, TEXT("3. hit casting end"));
		}
	}
}

void Aenemy_npc1_char::MoveRight_enemy_npc1_char(float Value)
{

		const float move_force = 1200.f;

		move_right = Value > 0 ? true : false;

		FRootMotionSource_ConstantForce* ConstantForce = new FRootMotionSource_ConstantForce();
		ConstantForce->InstanceName = "Dash";
		ConstantForce->AccumulateMode = ERootMotionAccumulateMode::Override;
		ConstantForce->Priority = 5;
		FVector player_location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		FVector enemy_npc1_char_location = GetActorLocation();
		float enemy_npc1_char_x_location = enemy_npc1_char_location.X;
		float player_x_location = player_location.X;
		float enemy_npc1_char_movement_direction = enemy_npc1_char_x_location - player_x_location;
		if (enemy_npc1_char_movement_direction < 0)
		{
			ConstantForce->Force = FVector(move_right ? 1.f : -1.f, 0.f, 0.f) * move_force;
		}
		else
		{
			ConstantForce->Force = FVector(move_right ? -1.f : 1.f, 0.f, 0.f) * move_force;
		}
		ConstantForce->Duration = 0.f;
		ConstantForce->StrengthOverTime = nullptr;
		ConstantForce->FinishVelocityParams.Mode = ERootMotionFinishVelocityMode::SetVelocity;
		ConstantForce->FinishVelocityParams.SetVelocity = FVector::ZeroVector;

		GetCharacterMovement()->ApplyRootMotionSource(ConstantForce);
}

void Aenemy_npc1_char::TouchStarted_enemy_npc1_char(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Jump on any touch
	Jump();
}

void Aenemy_npc1_char::TouchStopped_enemy_npc1_char(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Cease jumping once touch stopped
	StopJumping();
}

void Aenemy_npc1_char::UpdateCharacter_enemy_npc1_char()
{
	FVector player_location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	//update animation to match the motion
	UpdateAnimation_enemy_npc1_char();

	//now setup the rotation of the controller based on the direction npc is travelling
	const FVector NPCVelocity = player_location;
	float TravelDirection = NPCVelocity.X;
	//set the rotation so that the character faces his direction of travel.

	FVector enemy_npc1_char_location = GetActorLocation();
	float enemy_npc1_char_x_location = enemy_npc1_char_location.X;
	float player_x_location = player_location.X;
	float enemy_npc1_char_movement_direction = enemy_npc1_char_x_location - player_x_location;
	if (Controller != nullptr)
	{
		if (enemy_npc1_char_movement_direction <= 0)
		{
			SetActorRotation(FRotator(0.0, 180.0f, 0.0f));
		}
		else
		{
			SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
}