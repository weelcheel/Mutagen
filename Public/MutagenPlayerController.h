// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MutagenPlayerController.generated.h"

UCLASS()
class MUTAGEN_API AMutagenPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()
		
	virtual void Possess(APawn* aPawn) override;

	/** quests that the player receives */
	UPROPERTY(replicated)
	TArray<UQuest*> quests;

	/** distance before the player 'sees' someone, good for UI */
	float sightDistance;

public:

	/** adds a quest to the player's current quests */
	UFUNCTION(BlueprintCallable, Category = Quests)
	void AddQuest(UQuest* newQuest);

	/** get function for quests, useful for UI */
	UFUNCTION(BlueprintCallable, Category = Quests)
	void GetQuests(TArray<UQuest*>& outArray);

	/** gets the actor that the player is looking at */
	UFUNCTION(BlueprintCallable, Category = Interaction)
	AActor* GetActorCurrentlyLookingAt();
};
