///////////////////////////////////////////////////////////
//  Inventory.h
//  Implementation of the Class UInventory
//  Created on:      04-May-2015 11:13:50
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Array.h"
#include "Item.h"
#include "Object.h"
#include "Inventory.generated.h"

UCLASS()
class UInventory : public UObject
{
	GENERATED_BODY()

public:
	UInventory();

	TArray<AItem*> GetItems();
	void SetItems(TArray<AItem*> newVal);

private:
	TArray<AItem*> items;

};
