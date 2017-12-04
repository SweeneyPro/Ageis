// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SubmarineGameMode.h"
#include "SubmarineCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASubmarineGameMode::ASubmarineGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
