// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MutagenPlayerController.generated.h"

UCLASS()
class MUTAGEN_API AMutagenPlayerController : public APlayerController
{
	GENERATED_BODY()
		
		virtual void Possess(APawn* aPawn) override;


};
