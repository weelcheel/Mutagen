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


int32 AItem::GetAmount(){

	return amount;
}


void AItem::SetAmount(int32 newVal){

	amount = newVal;
}


int32 AItem::GetStackSize(){

	return stackSize;
}


void AItem::SetStackSize(int32 newVal){

	stackSize = newVal;
}


AItem* AItem::Copy() {
	AItem* newItem = ConstructObject<AItem>(AItem::StaticClass());
	newItem->SetName(GetName());
	newItem->SetAmount(GetAmount());
	newItem->SetStackSize(GetStackSize());
	newItem->SetType(GetType());
	newItem->SetGrade(GetGrade());
	newItem->SetOwner(GetOwner());
	return  newItem;
}