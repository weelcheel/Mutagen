///////////////////////////////////////////////////////////
//  UIComponentContainer.cpp
//  Implementation of the Class UUIComponentContainer
//  Created on:      28-May-2015 22:15:08
//  Original author: sam
///////////////////////////////////////////////////////////
#pragma once
#include "Mutagen.h"
#include "UIComponent.h"
#include "UIComponentContainer.h"

UUIComponentContainer::UUIComponentContainer(){

}


TArray<UUIComponent*> UUIComponentContainer::GetUIComponents(){
	return UIComponents;
}


void UUIComponentContainer::SetUIComponents(TArray<UUIComponent*> newVal){
	UIComponents = newVal;
}


TArray<UUIComponent*> UUIComponentContainer::GetSelectedComponents(){
	return selectedComponents;
}


void UUIComponentContainer::SetSelectedComponents(TArray<UUIComponent*> newVal){
	selectedComponents = newVal;
}


bool UUIComponentContainer::SelectComponent(UUIComponent* component){
	selectedComponents.Add(component);
	return true;
}


bool UUIComponentContainer::MoveComponents(TMap<TArray<UUIComponent*>, UUIComponentContainer*> components){
	for (auto& item : components){
		for (UUIComponent* component : item.Key){
			item.Value->RemoveUIComponent(component);
			AddUIComponent(component);
		}
	}
	return true;
}


void UUIComponentContainer::ResetSelection(){
	selectedComponents.Empty();
}


void UUIComponentContainer::RemoveUIComponent(UUIComponent* val){
	UIComponents.Remove(val);
}


void UUIComponentContainer::AddUIComponent(UUIComponent* val){
	UIComponents.Add(val);
}