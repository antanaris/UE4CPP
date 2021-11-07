// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4CPPGameMode.h"
#include "UE4CPPCharacter.h"
#include "MainPlayerState.h"
#include "UObject/ConstructorHelpers.h"

AUE4CPPGameMode::AUE4CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	};

	//Setting our default player state to be a MainPlayerState
	static ConstructorHelpers::FClassFinder<AMainPlayerState> PlayerStateBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/InventoryPlayerState"));
	if (PlayerStateBPClass.Class != NULL)
	{
		PlayerStateClass = PlayerStateBPClass.Class;
	};
}
