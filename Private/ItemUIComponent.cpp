///////////////////////////////////////////////////////////
//  ItemUIComponent.cpp
//  Implementation of the Class UItemUIComponent
//  Created on:      28-May-2015 21:51:17
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "ItemUIComponent.h"


UItemUIComponent::UItemUIComponent(){

}


bool UItemUIComponent::Select(){

	return false;
}


AItem* UItemUIComponent::GetItem(){
	return item;
}


void UItemUIComponent::SetItem(AItem* newVal){
	item = newVal;
}