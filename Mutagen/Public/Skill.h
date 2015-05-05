///////////////////////////////////////////////////////////
//  Skill.h
//  Implementation of the Class USkill
//  Created on:      04-May-2015 13:37:02
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
//#include "Activatable.h"
#include "Object.h"
#include "Skill.generated.h"

UCLASS()
class USkill : public UObject//, public UActivatable
{
	GENERATED_BODY()

public:
	USkill();

	void Activate();
	void Clone();

private:
	FString name;
	double cooldown;

};
