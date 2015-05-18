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

void UInventory::AddItem(AItem* newItem)
{
	items.Add(newItem);
}