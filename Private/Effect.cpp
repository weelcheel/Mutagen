///////////////////////////////////////////////////////////
//  UEffect.cpp
//  Implementation of the Class UEffect
//  Created on:      06-May-2015 17:28:21
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "Effect.h"

UEffect::UEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){

}

void UEffect::Activate(){
	if (OnEffectActivated.IsBound()){
		OnEffectActivated.Broadcast();
	}
}


UEffect* UEffect::CreateEffect(){
	UEffect& tempEffect = *ConstructObject<UEffect>(UEffect::StaticClass());
	return  &tempEffect;
}