// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BRGameMode.h"
#include "BRHUD.h"
#include "BRCharacter.h"
#include "BRGameState.h"
#include "BRPlayerController.h"
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

void ABRGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	AlivePlayers.Add(Cast<ABRPlayerController>(NewPlayer));
}

void ABRGameMode::PlayerDied(class ABRCharacter* Killed, class ABRCharacter* Killer)
{
	if (Killed)
	{
		if (ABRPlayerController* PC = Cast<ABRPlayerController>(Killed->GetController()))
		{
			AlivePlayers.RemoveSingle(PC);
		}

		// ToDo: Fix compile error with cast.
		/*if (AlivePlayers.Num() == 1 && AlivePlayers.IsValidIndex(0))
		{
			WinnerFound(Cast<ABRPlayerState>(AlivePlayers[0]->PlayerState));
		}*/
	}
}

void ABRGameMode::WinnerFound(class ABRPlayerState* Winner)
{
	if (ABRGameState* GS = GetGameState<ABRGameState>())
	{
		GS->Winner = Winner;
	}
}
