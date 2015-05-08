// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "QuestReward.generated.h"

/**
 * 
 */
UCLASS()
class MUTAGEN_API UQuestReward : public UObject
{
	GENERATED_BODY()
private:
	TArray<AItem*> rewards;

		

public:
	void GiveReward(AMutagenCharacter* questOwner);
	UQuestReward* CreateQuestReward();
	TArray<AItem*> GetRewards();
	void SetRewards(TArray<AItem*> newVal);
};
