///////////////////////////////////////////////////////////
//  USkillTree.h
//  Implementation of the Class USkillTree
//  Created on:      25-May-2015 17:22:32
//  Original author: sam
///////////////////////////////////////////////////////////
#pragma once
#include "Array.h"

class USkillTreeNode;

class USkillTree
{
private:
	TArray<USkillTreeNode*> nodes;

public:
	USkillTree(const FObjectInitializer& ObjectInitializer);

	void SelectNode(USkillTreeNode* nodeToSelect);
	void UnlockNode(USkillTreeNode* nodeToSelect);
	void Reset();

	TArray<USkillTreeNode*> GetNodes();

	void SetNodes(TArray<USkillTreeNode*> newVal);

};
