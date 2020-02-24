// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BRGameMode.h"
#include "BRHUD.h"
#include "BRCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABRGameMode::ABRGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABRHUD::StaticClass();
}
