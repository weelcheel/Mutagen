///////////////////////////////////////////////////////////
//  USkillTreeNode.cpp
//  Implementation of the Class USkillTreeNode
//  Created on:      25-May-2015 17:22:34
//  Original author: sam
///////////////////////////////////////////////////////////
#pragma once
#include "Mutagen.h"
#include "SkillTreeNode.h"


USkillTreeNode::USkillTreeNode(const FObjectInitializer& ObjectInitializer) {

}



float USkillTreeNode::GetX(){
	return x;
}


void USkillTreeNode::SetX(float newVal){
	x = newVal;
}


float USkillTreeNode::GetY(){
	return y;
}


void USkillTreeNode::SetY(float newVal){
	y = newVal;
}