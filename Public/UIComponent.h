///////////////////////////////////////////////////////////
//  UIComponent.h
//  Implementation of the Class UUIComponent
//  Created on:      28-May-2015 21:51:13
//  Original author: sam
///////////////////////////////////////////////////////////
#pragma once
class UUIComponent
{

public:
	UUIComponent();

	virtual bool Select();
	int GetPosition();
	void SetPosition(int newVal);

private:
	int position;

};
