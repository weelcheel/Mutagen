// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Mutagen.h"
#include "MutagenGameMode.h"
#include "MutagenHUD.h"
#include "MutagenPlayer.h"

AMutagenGameMode::AMutagenGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set default pawn class to our Blueprinted character
	DefaultPawnClass = AMutagenPlayer::StaticClass();

	// use our custom HUD class
	HUDClass = AMutagenHUD::StaticClass();
}
