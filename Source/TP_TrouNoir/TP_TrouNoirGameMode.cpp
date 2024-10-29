// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_TrouNoirGameMode.h"
#include "TP_TrouNoirCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATP_TrouNoirGameMode::ATP_TrouNoirGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
