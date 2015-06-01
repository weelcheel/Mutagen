// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Quest.generated.h"

class AMutagenCharacter;
class UQuestReward;
class UQuestObjective;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestCompleted, UQuest*, quest);

UCLASS(Blueprintable)
class MUTAGEN_API UQuest : public UObject
{
	GENERATED_BODY()
private:

	/** quest name */
	FString questName;

	TArray<UQuestReward*> rewards;
	TArray<UQuestObjective*> objectives;
	AMutagenCharacter* owner;

public:

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FQuestCompleted OnQuestCompleted;

	UFUNCTION(BlueprintCallable, Category = Quest)
		TArray<UQuestReward*> GetRewards();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetRewards(TArray<UQuestReward*> newVal);

	UFUNCTION(BlueprintCallable, Category = Quest)
		AMutagenCharacter* GetOwner();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetOwner(AMutagenCharacter* newVal);

	UFUNCTION(BlueprintCallable, Category = Quest)
		TArray<UQuestObjective*> GetObjectives();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetObjectives(TArray<UQuestObjective*> newVal);

	UFUNCTION(BlueprintCallable, Category = Quest)
		static UQuest* CreateQuest(AMutagenCharacter* character, TArray<UQuestObjective*> objectives, TArray<UQuestReward*> rewards, FString qName = "Default Quest");

	UFUNCTION(BlueprintCallable, Category = Quest)
		void ObjectiveUpdated(UQuestObjective* objective);

	UFUNCTION(BlueprintCallable, Category = Quest)
		bool IsComplete();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void AddObjective(UQuestObjective* inObjective);

	UFUNCTION(BlueprintCallable, Category = Quest)
		void AddReward(UQuestReward* inReward);

	UFUNCTION(BlueprintCallable, Category = Quest)
		void GiveRewards();

	UFUNCTION(BlueprintCallable, Category = Quest)
		FString GetQuestName();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void SetQuestName(FString newName);

	UFUNCTION(BlueprintCallable, Category = Quest)
		UQuestObjective* GetFirstObjective();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void AbandonQuest();
};
