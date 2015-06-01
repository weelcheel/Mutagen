// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Array.h"
#include "Item.h"
#include "SlotContainer.generated.h"

/**
 *
 */
UCLASS()
class MUTAGEN_API USlotContainer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		TArray<AItem*> GetItems();

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		void SetItems(TArray<AItem*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		AItem* AddItem(AItem* itemToAdd);

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		bool RemoveItem(AItem* itemToRemove);

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		int32 GetItemAmount(FString name);

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		int32 GetMaxItemCount();

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		void SetMaxItemCount(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Slot Container")
		bool HasSpace();

private:
	TArray<AItem*> items;
	int32 maxItemCount;

};
