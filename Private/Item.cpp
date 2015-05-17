///////////////////////////////////////////////////////////
//  AItem.cpp
//  Implementation of the Class AItem
//  Created on:      04-May-2015 11:16:11
//  Original author: sam
///////////////////////////////////////////////////////////
#include "Mutagen.h"
#include "Item.h"
#include "MutagenCharacter.h"

AItem::AItem(){

}

ItemEnumns::ItemType AItem::GetType(){
	return type;
}


void AItem::SetType(ItemEnumns::ItemType newVal){
	type = newVal;
}


FString AItem::GetName(){
	return name;
}


void AItem::SetName(FString newVal){
	name = newVal;
}


int32 AItem::GetGrade(){
	return grade;
}


void AItem::SetGrade(int32 newVal){
	grade = newVal;
}


AMutagenCharacter* AItem::GetItemOwner(){
	return owner;
}


void AItem::SetItemOwner(AMutagenCharacter* newVal){
	owner = newVal;
}


int AItem::GetAmount(){

	return amount;
}


void AItem::SetAmount(int newVal){

	amount = newVal;
}