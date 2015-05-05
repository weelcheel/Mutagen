///////////////////////////////////////////////////////////
//  Armour.cpp
//  Implementation of the Class AArmour
//  Created on:      04-May-2015 12:37:38
//  Original author: sam
///////////////////////////////////////////////////////////
#include "Mutagen.h"
#include "Armour.h"
#include "MutagenCharacter.h"


AArmour::AArmour(){

}


UStat* AArmour::GetArmourRatng(){
	return armourRatng;
}


void AArmour::SetArmourRatng(UStat* newVal){
	armourRatng = newVal;
}

void AArmour::UnEquip(AMutagenCharacter* entity) {

}

void AArmour::Equip(AMutagenCharacter* entity){

}