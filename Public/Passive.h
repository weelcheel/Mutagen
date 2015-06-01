///////////////////////////////////////////////////////////
//  Passive.h
//  Implementation of the Class UPassive
//  Created on:      06-May-2015 17:23:23
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once

#include "Array.h"
#include "Object.h"
#include "StatModifier.h"
#include "UnrealString.h"
#include "Passive.generated.h"

class UEffect;
class ABaseCharacter;

UCLASS(Blueprintable)
class UPassive : public UObject
{
	GENERATED_BODY()

public:
	UPassive(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Passive")
		TArray<FStatModifier> GetStatModifiers();

	UFUNCTION(BlueprintCallable, Category = "Passive")
		void SetStatModifiers(TArray<FStatModifier> newVal);

	UFUNCTION(BlueprintCallable, Category = "Passive")
		TArray<UEffect*> GetEffects();

	UFUNCTION(BlueprintCallable, Category = "Passive")
		void SetEffects(TArray<UEffect*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Passive")
		void ModifyStat(UStat* outStat, const UStat* originalStat);

	UFUNCTION(BlueprintCallable, Category = "Passive")
		static UPassive* CreatePassive(ABaseCharacter* owner, TArray<FStatModifier> modifier, TArray<UEffect*> effects);

	//UFUNCTION(BlueprintImplementableEvent, Category = "Passive")
	//static UPassive* Create(ABaseCharacter* owner, TArray<FStatModifier> modifier, TArray<UEffect*> effects);

	UFUNCTION(BlueprintCallable, Category = "Passive")
		ABaseCharacter* GetOwner();

	UFUNCTION(BlueprintCallable, Category = "Passive")
		void SetOwner(ABaseCharacter* newVal);

	UFUNCTION(BlueprintCallable, Category = "Passive")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Passive")
		void SetName(FString newVal);

private:
	TArray<FStatModifier> statModifiers;
	TArray<UEffect*> effects;
	ABaseCharacter* owner;
	FString name;
};
