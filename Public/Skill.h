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

UCLASS(Blueprintable)
class USkill : public UObject//, public UActivatable
{
	GENERATED_BODY()

public:
	USkill();

	/** called from Activate() to give an event hook in Blueprints */
	UFUNCTION(BlueprintImplementableEvent, Category = Skill)
	void HandleActivation();

	UFUNCTION(BlueprintCallable, Category = "Skill")
	void Activate();

	UFUNCTION(BlueprintCallable, Category = "Skill")
	void Clone();

	UFUNCTION(BlueprintCallable, Category = "Skill")
		double GetCooldown();

	UFUNCTION(BlueprintCallable, Category = "Skill")
		void SetCooldown(double newVal);

	UFUNCTION(BlueprintCallable, Category = "Skill")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Skill")
		void SetName(FString newVal);

private:
	FString name;
	double cooldown;

};
