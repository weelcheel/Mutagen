///////////////////////////////////////////////////////////
//  Passive.cpp
//  Implementation of the Class UPassive
//  Created on:      06-May-2015 17:23:23
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "Passive.h"
#include "Effect.h"

UPassive::UPassive(){

}

TArray<FStatModifier> UPassive::getStatModifiers(){

	return statModifiers;
}


void UPassive::setStatModifiers(TArray<FStatModifier> newVal){

	statModifiers = newVal;
}


TArray<UEffect*> UPassive::getEffects(){
	return effects;
}


void UPassive::setEffects(TArray<UEffect*> newVal){
	effects = newVal;
}