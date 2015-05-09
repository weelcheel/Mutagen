// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "MutagenPlayerController.h"
#include "Quest.h"
#include "Engine.h"
#include "UnrealNetwork.h"

void AMutagenPlayerController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
}

void AMutagenPlayerController::AddQuest(UQuest* newQuest)
{
	quests.AddUnique(newQuest);
}

void AMutagenPlayerController::GetQuests(TArray<UQuest*>& outArray)
{
	outArray = quests;
}

void AMutagenPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMutagenPlayerController, quests);
}
