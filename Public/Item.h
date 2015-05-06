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

UENUM(BlueprintType)
namespace GradeEnumns
{
	enum Grade
	{
		Wood,
		Tin,
		Copper,
		Iron,
		Steel
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
		GradeEnumns::Grade GetGrade();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetGrade(GradeEnumns::Grade newVal);

	UFUNCTION(BlueprintCallable, Category = "Item")
		AMutagenCharacter* GetItemOwner();

	UFUNCTION(BlueprintCallable, Category = "Item")
		void SetItemOwner(AMutagenCharacter* newVal);

private:
	TEnumAsByte<ItemEnumns::ItemType> type;
	FString name;
	TEnumAsByte<GradeEnumns::Grade> grade;
	AMutagenCharacter* owner;

};