///////////////////////////////////////////////////////////
//  SkillUIComponent.cpp
//  Implementation of the Class USkillUIComponent
//  Created on:      28-May-2015 21:51:10
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "SkillUIComponent.h"


USkillUIComponent::USkillUIComponent(){

}


bool USkillUIComponent::Select(){
	if (skill != NULL){
		skill->Activate();
		return true;
	}
	return false;
}


USkill* USkillUIComponent::GetSkill(){
	return skill;
}


void USkillUIComponent::SetSkill(USkill* newVal){
	skill = newVal;
}