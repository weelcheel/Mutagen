///////////////////////////////////////////////////////////
//  SkillUIComponent.h
//  Implementation of the Class USkillUIComponent
//  Created on:      28-May-2015 21:51:10
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Skill.h"
#include "UIComponent.h"

class USkillUIComponent : public UUIComponent
{

public:
	USkillUIComponent();

	bool Select() override;
	USkill* GetSkill();
	void SetSkill(USkill* newVal);

private:
	USkill* skill;

};
