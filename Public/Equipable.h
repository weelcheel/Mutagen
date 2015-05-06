///////////////////////////////////////////////////////////
//  Equipable.h
//  Implementation of the Interface Equipable
//  Created on:      27-Apr-2015 20:17:21
//  Original author: sam
///////////////////////////////////////////////////////////
#pragma once

class AMutagenCharacter;

class Equipable
{

public:
	Equipable() {}
	
	UFUNCTION(BlueprintCallable, Category = "Equipable")
		virtual void Equip(AMutagenCharacter* entity) { check(0 && "You must override this") };

	UFUNCTION(BlueprintCallable, Category = "Equipable")
		virtual void UnEquip(AMutagenCharacter* entity) { check(0 && "You must override this") };

	UFUNCTION(BlueprintCallable, Category = "Equipable")
		virtual bool IsEquiped() { return isEquiped; };

	UFUNCTION(BlueprintCallable, Category = "Equipable")
		virtual void SetEquiped(bool newVal) { isEquiped = newVal; };
private:
	bool isEquiped;
};
