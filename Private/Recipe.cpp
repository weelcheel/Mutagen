// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "Recipe.h"
#include "Item.h"
#include "MutagenCharacter.h"
#include "Inventory.h"

TArray<AItem*> URecipe::GetRequirements(){
	return requirements;
}


void URecipe::SetRequirements(TArray<AItem*> newVal){
	requirements = newVal;
}


TArray<AItem*> URecipe::GetOutput(){
	return output;
}


void URecipe::SetOutput(TArray<AItem*> newVal){
	output = newVal;
}


bool URecipe::HasRequirements(AMutagenCharacter* character) {
	static bool hasRequirements = true;
	UInventory* inventory = character->GetInventory();
	for (AItem* item : requirements){
		hasRequirements = (inventory->GetItemAmount(item->GetName()) < item->GetAmount()) && hasRequirements;
	}
	return false;
}


bool URecipe::ProduceOutput(AMutagenCharacter* character){
	static bool sucsessfull = true;
	if (HasRequirements(character)){
		for (AItem* item : output){
			sucsessfull = character->GetInventory()->AddItem(item) && sucsessfull;
		}
	}
	return sucsessfull;
}