// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CW_SOWGameMode.h"
#include "CW_SOWCharacter.h"

ACW_SOWGameMode::ACW_SOWGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ACW_SOWCharacter::StaticClass();	
}
