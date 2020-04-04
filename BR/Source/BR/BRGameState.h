// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BRGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWinnerFound);

/**
 * 
 */
UCLASS()
class BR_API ABRGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// The winner of the match.
	UPROPERTY(ReplicatedUsing = OnRep_Winner, Transient, BlueprintReadOnly, Category = "Game State")
	class ABRPlayerState* Winner = nullptr;

	UFUNCTION()
	void OnRep_Winner();

	// Called, when a winner as found.
	UPROPERTY(BlueprintAssignable, Category = "Game State")
	FWinnerFound OnWinnerFound;
};
