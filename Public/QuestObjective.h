// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "QuestObjective.generated.h"

class UQuest;

/**
 * 
 */
UCLASS()
class MUTAGEN_API UQuestObjective : public UObject
{
	GENERATED_BODY()
private:
	UQuest* quest;
	bool complete;
		
public:
	void SetUpListeners(UQuest* quest);
	bool IsComplete();
	void SetComplete(bool newVal);
	UQuest* GetQuest();
	void SetQuest(UQuest* newVal);
	UQuestObjective* CreateQuestObjective();
	void NotifyQuest();
};
