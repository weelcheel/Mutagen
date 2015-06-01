///////////////////////////////////////////////////////////
//  UIComponent.cpp
//  Implementation of the Class UUIComponent
//  Created on:      28-May-2015 21:51:13
//  Original author: sam
///////////////////////////////////////////////////////////
#pragma once
#include "Mutagen.h"
#include "UIComponent.h"


UUIComponent::UUIComponent(){

}


bool UUIComponent::Select(){
	return false;
}


int UUIComponent::GetPosition(){
	return position;
}


void UUIComponent::SetPosition(int newVal){
	position = newVal;
}