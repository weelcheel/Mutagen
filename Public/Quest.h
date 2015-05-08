// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Quest.generated.h"

class AMutagenCharacter;
class UQuestReward;
class UQuestObjective;

UCLASS()
class MUTAGEN_API UQuest : public UObject
{
	GENERATED_BODY()
private:
	TArray<UQuestReward*> rewards;
	TArray<UQuestObjective*> objectives;
	AMutagenCharacter* owner;

public:
	TArray<UQuestReward*> GetRewards();
	void SetRewards(TArray<UQuestReward*> newVal);

	AMutagenCharacter* GetOwner();
	void SetOwner(AMutagenCharacter* newVal);

	TArray<UQuestObjective*> GetObjectives();
	void SetObjectives(TArray<UQuestObjective*> newVal);

	UQuest* CreateQuest(AMutagenCharacter* character, TArray<UQuestObjective*> objectives = *new TArray<UQuestObjective*>(), TArray<UQuestReward*> rewards = *new TArray<UQuestReward*>());

	void ObjectiveUpdated(UQuestObjective* objective);
	bool IsComplete();

	void AddObjective(UQuestObjective* inObjective);
	void AddReward(UQuestReward* inReward);
	void GiveRewards();
};
