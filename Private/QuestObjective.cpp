// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "QuestObjective.h"
#include "Quest.h"


void UQuestObjective::SetUpListeners(UQuest* quest){
	SetQuest(quest);
	if (quest->GetOwner() != NULL){
		AMutagenCharacter& character = *quest->GetOwner();
		
	
	}
}


bool UQuestObjective::IsComplete(){
	return complete;
}


void UQuestObjective::SetComplete(bool newVal){
	complete = newVal;
}


UQuest* UQuestObjective::GetQuest(){
	return quest;
}


void UQuestObjective::SetQuest(UQuest* newVal){
	quest = newVal;
}


UQuestObjective* UQuestObjective::CreateQuestObjective(FString oText){
	UQuestObjective* tempQuestObjective = ConstructObject<UQuestObjective>(UQuestObjective::StaticClass());
	tempQuestObjective->SetObjectiveText(oText);
	return tempQuestObjective;
}


void UQuestObjective::NotifyQuest(){
	if (GetQuest() != NULL){
		GetQuest()->ObjectiveUpdated(this);
	}

	if (OnObjectiveCompleted.IsBound() && IsComplete()){
		OnObjectiveCompleted.Broadcast(this);
	}
	else if (OnObjectiveUpdated.IsBound()){
		OnObjectiveUpdated.Broadcast(this);
	}
}

FString UQuestObjective::GetObjectiveText()
{
	return objectiveText;
}

void UQuestObjective::SetObjectiveText(FString newName)
{
	objectiveText = newName;
}