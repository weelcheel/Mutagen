///////////////////////////////////////////////////////////
//  USkillTree.cpp
//  Implementation of the Class USkillTree
//  Created on:      25-May-2015 17:22:32
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Mutagen.h"
#include "SkillTree.h"
#include "SkillTreeNode.h"


USkillTree::USkillTree(const FObjectInitializer& ObjectInitializer) {

}


void USkillTree::SelectNode(USkillTreeNode* nodeToSelect){

}


void USkillTree::UnlockNode(USkillTreeNode* nodeToSelect){

}


void USkillTree::Reset(){

}

TArray<USkillTreeNode*> USkillTree::GetNodes(){

	return nodes;
}


void USkillTree::SetNodes(TArray<USkillTreeNode*> newVal){

	nodes = newVal;
}