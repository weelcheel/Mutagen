#pragma once
#include "UnrealString.h"
#include "StatModifier.generated.h"

USTRUCT(BlueprintType)
struct FStatModifier
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatModifier")
		float amount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatModifier")
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatModifier")
		bool positive = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StatModifier")
		bool percentage = false;
};