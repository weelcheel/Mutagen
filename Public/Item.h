///////////////////////////////////////////////////////////
//  AItem.h
//  Implementation of the Class AItem
//  Created on:      04-May-2015 11:16:11
//  Original author: sam
///////////////////////////////////////////////////////////

UENUM(BlueprintType, Blueprintable)
namespace ItemEnumns
{
	enum ItemType
	{
		Resource,
		Armour,
		Weapon
	};
}

#pragma once
#include "UnrealString.h"
#include "Item.generated.h"

class AMutagenCharacter;

UCLASS()
class AItem : public AActor
{
	GENERATED_BODY()
public:
	AItem();
	AItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){};


	UFUNCTION(BlueprintCallable, Category = "Item")
		ItemEnumns::ItemType GetType();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetType(ItemEnumns::ItemType newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetName(FString newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		int32 GetGrade();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetGrade(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		AMutagenCharacter* GetItemOwner();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetItemOwner(AMutagenCharacter* newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		int32 GetAmount();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetAmount(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		int32 GetStackSize();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetStackSize(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		AItem* Copy();

	FORCEINLINE AItem& operator+(AItem &aitem)
	{
		AItem* nitem = ConstructObject<AItem>(AItem::StaticClass());
		if (nitem)
		{
			nitem->amount = aitem.amount + amount;
		}

		return *nitem;
	}

	FORCEINLINE AItem& operator+=(AItem &aitem)
	{
		amount += aitem.amount;

		return *this;
	}
	FORCEINLINE AItem& operator-(AItem &aitem)
	{
		AItem* nitem = ConstructObject<AItem>(AItem::StaticClass());
		if (nitem)
		{
			nitem->amount = aitem.amount - amount;
		}

		return *nitem;
	}

	FORCEINLINE AItem& operator-=(AItem &aitem)
	{
		amount -= aitem.amount;

		return *this;
	}

private:
	TEnumAsByte<ItemEnumns::ItemType> type;
	FString name;
	int32 grade;
	AMutagenCharacter* owner;
	int32 amount;
	int32 stackSize;

};