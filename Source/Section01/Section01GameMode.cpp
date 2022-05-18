// Copyright Epic Games, Inc. All Rights Reserved.

#include "Section01GameMode.h"
#include "Section01Character.h"
#include "UObject/ConstructorHelpers.h"

ASection01GameMode::ASection01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
