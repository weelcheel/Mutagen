///////////////////////////////////////////////////////////
//  USkillTreeNode.h
//  Implementation of the Class USkillTreeNode
//  Created on:      25-May-2015 17:22:34
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
class USkillTreeNode
{
private:
	float x;
	float y;


public:
	USkillTreeNode(const FObjectInitializer& ObjectInitializer);
	float GetX();
	void SetX(float newVal);
	float GetY();
	void SetY(float newVal);

};
