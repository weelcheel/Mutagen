///////////////////////////////////////////////////////////
//  ItemUIComponent.h
//  Implementation of the Class UItemUIComponent
//  Created on:      28-May-2015 21:51:17
//  Original author: sam
///////////////////////////////////////////////////////////

#include "UIComponent.h"
#include "Item.h"

class UItemUIComponent : public UUIComponent
{

public:
	UItemUIComponent();

	bool Select() override;
	AItem* GetItem();
	void SetItem(AItem* newVal);

private:
	AItem* item;

};
