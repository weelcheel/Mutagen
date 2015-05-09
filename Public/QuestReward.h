// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "QuestReward.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class MUTAGEN_API UQuestReward : public UObject
{
	GENERATED_BODY()
private:
	TArray<AItem*> rewards;

public:

	UFUNCTION(BlueprintCallable, Category = Quest)
		void GiveReward(AMutagenCharacter* questOwner);

	UFUNCTION(BlueprintCallable, Category = Quest)
		UQuestReward* CreateQuestReward();

	UFUNCTION(BlueprintCallable, Category = Quest)
		TArray<AItem*> GetRewards();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetRewards(TArray<AItem*> newVal);
};
