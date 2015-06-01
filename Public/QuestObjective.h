// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "QuestObjective.generated.h"

class UQuest;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectiveCompleted, UQuestObjective*, objective);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectiveUpdated, UQuestObjective*, objective);

UCLASS(Blueprintable)
class MUTAGEN_API UQuestObjective : public UObject
{
	GENERATED_BODY()
private:

	/** text describing the objective */
	FString objectiveText;

	UQuest* quest;
	bool complete;

public:

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FObjectiveCompleted OnObjectiveCompleted;

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FObjectiveUpdated OnObjectiveUpdated;

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetUpListeners(UQuest* quest);

	UFUNCTION(BlueprintCallable, Category = Quest)
		bool IsComplete();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetComplete(bool newVal);

	UFUNCTION(BlueprintCallable, Category = Quest)
		UQuest* GetQuest();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetQuest(UQuest* newVal);

	UFUNCTION(BlueprintCallable, Category = QuestObjective)
		static UQuestObjective* CreateQuestObjective(FString oText = "Default Objective");

	UFUNCTION(BlueprintCallable, Category = Quest)
		void NotifyQuest();

	UFUNCTION(BlueprintCallable, Category = Quest)
		FString GetObjectiveText();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetObjectiveText(FString newName);
};
