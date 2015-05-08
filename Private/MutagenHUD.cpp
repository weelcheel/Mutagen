// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Mutagen.h"
#include "MutagenHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Engine.h"

AMutagenHUD::AMutagenHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bShowOverlays = true;
}


void AMutagenHUD::DrawHUD()
{
	Super::DrawHUD();

	
}

void AMutagenHUD::BeginPlay()
{
	Super::BeginPlay();

	//add every character to be able to post render info about them
	for (TActorIterator<AMutagenCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AddPostRenderedActor(*ActorItr);
	}
}