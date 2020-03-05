// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
//version 2.0

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "CW_SOWCharacter.h"
#include "enemy_npc1_char.generated.h"

class UTextRenderComponent;

/**
 * This class is the default character for CW_SOW, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS(config = Game)
class Aenemy_npc1_char : public APaperCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UTextRenderComponent* TextComponent;
	virtual void Tick(float DeltaSeconds) override;
protected:
	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation_enemy_npc1_char();

	/** Called for side to side input */
	void MoveRight_enemy_npc1_char(float Value);

	void UpdateCharacter_enemy_npc1_char();

	/** Handle touch inputs. */
	void TouchStarted_enemy_npc1_char(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped_enemy_npc1_char(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


	bool move_2_player;
	bool move_right;
	bool b_player_dash_enabled;

public:

	ACW_SOWCharacter * PlayerCharPtr;

	Aenemy_npc1_char();
	bool GetHit();
	void HitPlayerCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	virtual void BeginPlay() override;
};
