///////////////////////////////////////////////////////////
//  Armour.h
//  Implementation of the Class AArmour
//  Created on:      04-May-2015 12:37:38
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Stat.h"
#include "Item.h"
#include "Equipable.h"
#include "Armour.generated.h"


UCLASS(Blueprintable)
class AArmour : public AItem, public Equipable
{
	GENERATED_BODY()

public:
	AArmour();

	UFUNCTION(BlueprintCallable, Category = "Equipable")
		virtual void UnEquip(AMutagenCharacter* entity);

	UFUNCTION(BlueprintCallable, Category = "Equipable")
		virtual void Equip(AMutagenCharacter* entity);

	UFUNCTION(BlueprintCallable, Category = "Armour")
		UStat* GetArmourRatng();

	UFUNCTION(BlueprintCallable, Category = "Armour")
		void SetArmourRatng(UStat* newVal);
private:
	UStat* armourRatng;

};
