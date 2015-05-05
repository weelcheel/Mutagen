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


UCLASS()
class AArmour : public AItem, public Equipable
{
	GENERATED_BODY()

public:
	AArmour();

	virtual void UnEquip(AMutagenCharacter* entity);
	virtual void Equip(AMutagenCharacter* entity);

	UStat* GetArmourRatng();
	void SetArmourRatng(UStat* newVal);

private:
	UStat* armourRatng;

};
