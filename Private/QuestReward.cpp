// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "QuestReward.h"


void UQuestReward::GiveReward(AMutagenCharacter* questOwner){

}


UQuestReward* UQuestReward::CreateQuestReward(){
	UQuestReward* tempQuestReward = ConstructObject<UQuestReward>(UQuestReward::StaticClass());
	return tempQuestReward;
}


TArray<AItem*> UQuestReward::GetRewards(){
	return rewards;
}


void UQuestReward::SetRewards(TArray<AItem*> newVal){
	rewards = newVal;
}