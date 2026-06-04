// Copyright Epic Games, Inc. All Rights Reserved.

#include "Advanced_0604GameMode.h"
#include "Advanced_0604Character.h"
#include "UObject/ConstructorHelpers.h"

AAdvanced_0604GameMode::AAdvanced_0604GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
