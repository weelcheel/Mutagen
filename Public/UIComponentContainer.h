///////////////////////////////////////////////////////////
//  UIComponentContainer.h
//  Implementation of the Class UUIComponentContainer
//  Created on:      28-May-2015 22:15:07
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Array.h"
class UUIComponent;
class UUIComponentContainer;

class UUIComponentContainer
{

public:
	UUIComponentContainer();

	TArray<UUIComponent*> GetUIComponents();
	void SetUIComponents(TArray<UUIComponent*> newVal);

	TArray<UUIComponent*> GetSelectedComponents();
	void SetSelectedComponents(TArray<UUIComponent*> newVal);

	bool SelectComponent(UUIComponent* component);
	bool MoveComponents(TMap<TArray<UUIComponent*>, UUIComponentContainer*> components);

	void ResetSelection();

	void RemoveUIComponent(UUIComponent* val);

	void AddUIComponent(UUIComponent* val);

private:
	TArray<UUIComponent*> UIComponents;
	TArray<UUIComponent*> selectedComponents;
};
