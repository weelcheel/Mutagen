///////////////////////////////////////////////////////////
//  UEffect.h
//  Implementation of the Class UEffect
//  Created on:      06-May-2015 17:28:21
//  Original author: sam
///////////////////////////////////////////////////////////


#pragma once
#include "Object.h"
#include "Effect.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEffectActivated);

UCLASS(Blueprintable)
class UEffect : public UObject
{
	GENERATED_BODY()

public:
	UEffect(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FEffectActivated OnEffectActivated;

	UFUNCTION(BlueprintCallable, Category = "Effect")
		void Activate();

	UFUNCTION(BlueprintCallable, Category = "Effect")
		static UEffect* CreateEffect();
};
