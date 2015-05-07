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
	DefaultPawnClass = AMutagenPlayer::StaticClass();
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Character/Player"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerControllerClass = AMutagenPlayerController::StaticClass();

	// use our custom HUD class
	HUDClass = AMutagenHUD::StaticClass();
}