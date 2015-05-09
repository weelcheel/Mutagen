// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MutagenPlayerController.generated.h"

UCLASS()
class MUTAGEN_API AMutagenPlayerController : public APlayerController
{
	GENERATED_BODY()
		
	virtual void Possess(APawn* aPawn) override;

	/** quests that the player receives */
	UPROPERTY(replicated)
	TArray<UQuest*> quests;

public:

	/** adds a quest to the player's current quests */
	UFUNCTION(BlueprintCallable, Category = Quests)
	void AddQuest(UQuest* newQuest);

	/** get function for quests, useful for UI */
	UFUNCTION(BlueprintCallable, Category = Quests)
	void GetQuests(TArray<UQuest*>& outArray);
};
