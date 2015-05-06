///////////////////////////////////////////////////////////
//  Passive.h
//  Implementation of the Class UPassive
//  Created on:      06-May-2015 17:23:23
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once

#include "StatModifier.h"
#include "Array.h"
#include "Object.h"
#include "Passive.generated.h"

class UEffect;

UCLASS(Blueprintable)
class UPassive : public UObject
{
	GENERATED_BODY()

public:
	UPassive();

	TArray<FStatModifier> getStatModifiers();
	void setStatModifiers(TArray<FStatModifier> newVal);

	TArray<UEffect*> getEffects();
	void setEffects(TArray<UEffect*> newVal);

private:
	TArray<FStatModifier> statModifiers;
	TArray<UEffect*> effects;

};
