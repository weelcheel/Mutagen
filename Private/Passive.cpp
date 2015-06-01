///////////////////////////////////////////////////////////
//  Passive.cpp
//  Implementation of the Class UPassive
//  Created on:      06-May-2015 17:23:23
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "Passive.h"
#include "Effect.h"
#include "Stat.h"
#include "BaseCharacter.h"

UPassive::UPassive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){

}

TArray<FStatModifier> UPassive::GetStatModifiers(){
	return statModifiers;
}


void UPassive::SetStatModifiers(TArray<FStatModifier> newVal){
	statModifiers = newVal;
}


TArray<UEffect*> UPassive::GetEffects(){
	return effects;
}


void UPassive::SetEffects(TArray<UEffect*> newVal){
	effects = newVal;
}


void UPassive::ModifyStat(UStat* outStat, const UStat* originalStat ){
	for (FStatModifier modifier : statModifiers) {
		if (modifier.name.Equals(outStat->GetName())){
			if (modifier.positive) {
				if (modifier.percentage){
					float newValue = outStat->GetValue() + (outStat->GetValue() *  modifier.amount);
					outStat->SetValue(newValue);
				}
				else {
					outStat->SetValue(outStat->GetValue() + modifier.amount);
				}
			}
			else {
				if (modifier.percentage){
					float newValue = outStat->GetValue() - (outStat->GetValue() *  modifier.amount);
					outStat->SetValue(newValue);
				}
				else {
					outStat->SetValue(outStat->GetValue() - modifier.amount);
				}
			}
		}
	}
}


UPassive* UPassive::CreatePassive(ABaseCharacter* owner, TArray<FStatModifier> modifier, TArray<UEffect*> effects = *new TArray<UEffect*>()){
	UPassive& tempPassive = *ConstructObject<UPassive>(UPassive::StaticClass());
	tempPassive.SetStatModifiers(modifier);
	tempPassive.SetEffects(effects);
	tempPassive.SetOwner(owner);
	return &tempPassive;
}

//UPassive* UPassive::Create(ABaseCharacter* owner, TArray<FStatModifier> modifier, TArray<UEffect*> effects){
//}


ABaseCharacter* UPassive::GetOwner(){
	return owner;
}


void UPassive::SetOwner(ABaseCharacter* newVal){
	owner = newVal;
}


FString UPassive::GetName(){

	return name;
}


void UPassive::SetName(FString newVal){

	name = newVal;
}