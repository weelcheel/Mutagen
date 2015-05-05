///////////////////////////////////////////////////////////
//  AItem.h
//  Implementation of the Class AItem
//  Created on:      04-May-2015 11:16:11
//  Original author: sam
///////////////////////////////////////////////////////////

UENUM(BlueprintType)
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

	ItemEnumns::ItemType GetType();
	void SetType(ItemEnumns::ItemType newVal);

	FString GetName();
	void SetName(FString newVal);

	GradeEnumns::Grade GetGrade();
	void SetGrade(GradeEnumns::Grade newVal);
	AMutagenCharacter* GetOwner();
	void SetOwner(AMutagenCharacter* newVal);

private:
	TEnumAsByte<ItemEnumns::ItemType> type;
	FString name;
	TEnumAsByte<GradeEnumns::Grade> grade;
	AMutagenCharacter* owner;

};