// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "TradeManager.h"
#include "MutagenCharacter.h"
#include "Inventory.h" 

UTradeManager::UTradeManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){
	SetEntitiesInvolved(*new TArray<AMutagenCharacter*>());
	SetItemsInvolved(*new TMap<AItem*, AMutagenCharacter*>());
	SetTradeComplete(false);
}

/* Adds an item to the trade */
void UTradeManager::AddItemToTrade(AMutagenCharacter* entity, AItem* itemToAdd){
	GetItemsInvolved().Add(itemToAdd, entity);
}

/* Checks to see if the trade is of equal worth */
bool UTradeManager::IsTradeValid(){
	TArray<int32> totals = *new TArray<int32>();
	totals[0] = 0;
	totals[1] = 0;

	AMutagenCharacter* character = GetEntitiesInvolved()[0];

	for (auto& item : GetItemsInvolved())
	{
		if (item.Value == character){
			totals[0] += item.Key->GetAmount() * item.Key->GetGrade();
		}
		else {
			totals[1] += item.Key->GetAmount() * item.Key->GetGrade();
		}
	}
	
	return totals[0] == totals[1];
}


/* Clears the old trade, if any, and starts a new one */
void UTradeManager::BeginTrade(TArray<AMutagenCharacter*> newVal){
	ClearTrade();
	SetEntitiesInvolved(newVal);
}


/* Clears the current trade */
void UTradeManager::ClearTrade(){
	SetEntitiesInvolved(*new TArray<AMutagenCharacter*>());
	SetItemsInvolved(*new TMap<AItem*, AMutagenCharacter*>());
	SetTradeComplete(false);
}


/* Gets all the items within the current trade owned by the character */
TArray<AItem*> UTradeManager::GetItems(AMutagenCharacter* character){
	TArray<AItem*> items = *new TArray<AItem*>();

	for (auto& item : GetItemsInvolved())
	{
		if (item.Value == character){
			items.Add(item.Key);
		}
	}

	return  items;
}


/* Removes an item from the trade*/
void UTradeManager::RemoveItemFromTrade(AItem* itemToRemove){
	GetItemsInvolved().Remove(itemToRemove);
}


/* Changes the amount of an item within the current trade */
void UTradeManager::EditItemInTrade(AMutagenCharacter* entity, AItem* itemToChange, bool positive){
	for (auto& item : GetItemsInvolved())
	{
		// Does the item belong to this enetiy and is it the same item
		if (item.Value == entity && item.Key->GetName().Equals(itemToChange->GetName())){
			// Calculate the new amount
			int amount = item.Key->GetAmount() + (positive ? itemToChange->GetAmount() : -itemToChange->GetAmount());

			// If it's greater than 0 then change it else remove it
			if (amount > 0) {
				item.Key->SetAmount(amount);
			}
			else {
				RemoveItemFromTrade(item.Key);
			}
		}
	}
}


/* Exchanges the items between players within the current trade */
void UTradeManager::CompleteTrade(){
	for (AMutagenCharacter* character : GetEntitiesInvolved()){
		for (auto& item : GetItemsInvolved())
		{
			// If the current character deosn't own the item then give it to them
			if (item.Value != character){
				character->GetInventory()->GetItems().Add(item.Key);
			}
			else { // Otherwise remove it from thier inventory
				character->GetInventory()->GetItems().Remove(item.Key);
			}

		}
	}
}


TMap<AItem*, AMutagenCharacter*> UTradeManager::GetItemsInvolved(){
	return itemsInvolved;
}


void UTradeManager::SetItemsInvolved(TMap<AItem*, AMutagenCharacter*> newVal){
	itemsInvolved = newVal;
}

TArray<AMutagenCharacter*> UTradeManager::GetEntitiesInvolved(){
	return entitiesInvolved;
}


void UTradeManager::SetEntitiesInvolved(TArray<AMutagenCharacter*> newVal){
	entitiesInvolved = newVal;
}


bool UTradeManager::IsTradeComplete(){
	return tradeComplete;
}


void UTradeManager::SetTradeComplete(bool newVal){
	tradeComplete = newVal;
}