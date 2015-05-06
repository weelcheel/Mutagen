#pragma once
#include "UnrealString.h"
#include "StatModifier.generated.h"

USTRUCT(BlueprintType)
struct FStatModifier
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
		int32 amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
		bool positive;

};