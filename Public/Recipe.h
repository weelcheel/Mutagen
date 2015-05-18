// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Recipe.generated.h"

class AItem;
class AMutagenCharacter;

UCLASS()
class MUTAGEN_API URecipe : public UObject
{
	GENERATED_BODY()
private:
	TArray<AItem*> requirements;
	TArray<AItem*> output;
public:
	UFUNCTION(BlueprintCallable, Category = "Recipe")
		TArray<AItem*> GetRequirements();

	UFUNCTION(BlueprintCallable, Category = "Recipe")
		void SetRequirements(TArray<AItem*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Recipe")
		TArray<AItem*> GetOutput();

	UFUNCTION(BlueprintCallable, Category = "Recipe")
		void SetOutput(TArray<AItem*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Recipe")
		bool HasRequirements(AMutagenCharacter* character);

	UFUNCTION(BlueprintCallable, Category = "Recipe")
		bool ProduceOutput(AMutagenCharacter* character);
};
