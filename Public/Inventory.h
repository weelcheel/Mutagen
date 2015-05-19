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

UCLASS(Blueprintable)
class UInventory : public UObject
{
	GENERATED_BODY()

public:
	UInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		TArray<AItem*> GetItems();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void SetItems(TArray<AItem*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		AItem* AddItem(AItem* itemToAdd);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool RemoveItem(AItem* itemToRemove);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int32 GetItemAmount(FString name);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int32 GetMaxItemCount();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void SetMaxItemCount(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool HasSpace();

private:
	TArray<AItem*> items;
	int32 maxItemCount;
};
