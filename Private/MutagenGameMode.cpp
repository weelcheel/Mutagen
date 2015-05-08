// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Mutagen.h"
#include "MutagenGameMode.h"
#include "MutagenHUD.h"
#include "MutagenPlayer.h"
#include "MutagenPlayerController.h"

AMutagenGameMode::AMutagenGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Mutagen/Blueprints/Character/DemoPlayer"));
	if (PlayerPawnClassFinder.Succeeded())
	{
		DefaultPawnClass = PlayerPawnClassFinder.Class;
	}
*/
	// use our custom HUD class
	HUDClass = AMutagenHUD::StaticClass();
}
