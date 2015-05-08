///////////////////////////////////////////////////////////
//  Skill.cpp
//  Implementation of the Class USkill
//  Created on:      04-May-2015 13:37:02
//  Original author: sam
///////////////////////////////////////////////////////////
#include "Mutagen.h"
#include "Skill.h"


USkill::USkill(){

}

void USkill::Activate()
{
	HandleActivation();
}


void USkill::Clone(){

}


double USkill::GetCooldown(){

	return cooldown;
}


void USkill::SetCooldown(double newVal){
	cooldown = newVal;
}


FString USkill::GetName(){
	return name;
}


void USkill::SetName(FString newVal){
	name = newVal;
}
