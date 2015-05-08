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


UQuestObjective* UQuestObjective::CreateQuestObjective(){
	UQuestObjective* tempQuestObjective = ConstructObject<UQuestObjective>(UQuestObjective::StaticClass());
	return tempQuestObjective;

}


void UQuestObjective::NotifyQuest(){
	if (GetQuest() != NULL){
		GetQuest()->ObjectiveUpdated(this);
	}
}