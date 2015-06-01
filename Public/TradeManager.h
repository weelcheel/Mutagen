// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Containers/Map.h"
#include "Array.h"
#include "TradeManager.generated.h"

class AMutagenCharacter;
class AItem;

UCLASS()
class MUTAGEN_API UTradeManager : public UObject
{
	GENERATED_BODY()
private:
	TArray<AMutagenCharacter*> entitiesInvolved;
	bool tradeComplete;
	TMap<AItem*, AMutagenCharacter*> itemsInvolved;

public:
	UTradeManager(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		TArray<AMutagenCharacter*> GetEntitiesInvolved();

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void SetEntitiesInvolved(TArray<AMutagenCharacter*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		bool IsTradeComplete();

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void SetTradeComplete(bool newVal);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void AddItemToTrade(AMutagenCharacter* entity, AItem* itemToAdd);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		bool IsTradeValid();

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void ClearTrade();

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void RemoveItemFromTrade(AItem* itemToRemove);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void EditItemInTrade(AMutagenCharacter* entity, AItem* itemToChange, bool positive = true);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		void CompleteTrade();

	TMap<AItem*, AMutagenCharacter*> GetItemsInvolved();

	void SetItemsInvolved(TMap<AItem*, AMutagenCharacter*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Trade")
		TArray<AItem*> GetItems(AMutagenCharacter* character);
	void BeginTrade(TArray<AMutagenCharacter*> newVal);
};
