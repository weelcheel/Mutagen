// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "MutagenHUD.generated.h"

UCLASS()
class AMutagenHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMutagenHUD(const FObjectInitializer& ObjectInitializer);

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	/** overidden so that we can post render actors for HUD */
	void BeginPlay() override;

};

