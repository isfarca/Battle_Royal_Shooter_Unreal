// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BRGameMode.generated.h"

UCLASS(minimalapi)
class ABRGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABRGameMode();

	void PostLogin(APlayerController* NewPlayer) override;

	void PlayerDied(class ABRCharacter* Killed, class ABRCharacter* Killer);

	void WinnerFound(class ABRPlayerState* Winner);

	UPROPERTY(Transient)
	TArray<class ABRPlayerController*> AlivePlayers;
};



