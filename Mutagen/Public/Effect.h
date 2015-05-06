///////////////////////////////////////////////////////////
//  UEffect.h
//  Implementation of the Class UEffect
//  Created on:      06-May-2015 17:28:21
//  Original author: sam
///////////////////////////////////////////////////////////


#pragma once
#include "Object.h"
#include "Effect.generated.h"

UCLASS(Blueprintable)
class UEffect : public UObject
{
	GENERATED_BODY()

public:
	UEffect();

	void Activate();


};
