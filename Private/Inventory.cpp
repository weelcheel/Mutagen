///////////////////////////////////////////////////////////
//  Inventory.cpp
//  Implementation of the Class UInventory
//  Created on:      04-May-2015 11:13:50
//  Original author: sam
///////////////////////////////////////////////////////////
#include "Mutagen.h"
#include "Inventory.h"


UInventory::UInventory(){

}


TArray<AItem*> UInventory::GetItems(){
	return items;
}

void UInventory::SetItems(TArray<AItem*> newVal){
	items = newVal;
}

/* Adds an item to the inventory, if it finds an item with less than StackSize it adds the amount
 * else it will create a new item with the remaining amount and set the one found to StackSize
 */
bool UInventory::AddItem(AItem* itemToAdd){
	for (AItem* item : GetItems()){
		// Finds the first item with space avaible with a matching name
		if (item->GetName().Equals(itemToAdd->GetName()) && item->GetAmount() < item->GetStackSize()){
			int32 amountOfSpace = item->GetStackSize() - item->GetAmount();

			// If there is enough space left just add to it
			if (amountOfSpace >= 0){
				item->SetAmount(item->GetAmount() + itemToAdd->GetAmount());
				return true;
			}
			else { // Otherwise max the amount and adda new item to the inventory
				// At this stage will we need to check if their inventory is full
				if (GetItems().Num() < GetMaxItemCount()) {
					item->SetAmount(item->GetStackSize());
					AItem* newItem = item->Copy();
					newItem->SetAmount(-amountOfSpace);
					GetItems().Add(newItem);
					return true;
				else {
					return false;	
				}
			}
		}
	}

	// We didn't find an existing item so add it
	// At this stage will we need to check if their inventory is full
	if (GetItems().Num() < GetMaxItemCount()) {
		GetItems().Add(itemToAdd);
		return true;
	}
	else {
		return false;
	}
}

/* This will reduce the an items amount by the given item if found */
bool UInventory::RemoveItem(AItem* itemToRemove) {

	// Is there only one item of this type in out inventory
	bool isAtMax = GetItemAmount(itemToRemove->GetName()) == itemToRemove->GetStackSize();

	for (AItem* item : GetItems()){

		// Find the first item with the same name and is either the only item or not at max stack size
		if (item->GetName().Equals(itemToRemove->GetName()) && (isAtMax || item->GetAmount() < item->GetStackSize())){
			int32 amountLeft = item->GetAmount() - itemToRemove->GetAmount();

			// We don't remove items we don't have 
			if (amountLeft < 0){
				return false;
			}
			else if (amountLeft == 0){ // Simply remove it if the amount left is 0
				GetItems().Remove(item);
				return true;
			}
			else { // Just change the amount
				item->SetAmount(amountLeft);
				return true;
			}
		}
	}

	return false;
}

/* Returns the total amount of items for the given name */
int32 UInventory::GetItemAmount(FString name){
	int32 total = 0;
	for (AItem* item : GetItems()){
		if (item->GetName().Equals(name)){
			total += item->GetAmount();
		}
	}
	return total;
}

/* Gets the maximumn amount of items this inventory can have */
int32 UInventory::GetMaxItemCount(){
	return maxItemCount;
}


/* Sets the maximumn amount of items this inventory can have */
void UInventory::SetMaxItemCount(int32 newVal){
	maxItemCount = newVal;
}
