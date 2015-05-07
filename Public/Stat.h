///////////////////////////////////////////////////////////
//  UStat.h
//  Implementation of the Class UStat
//  Created on:      04-May-2015 12:29:29
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Object.h"
#include "UnrealString.h"
#include "Stat.generated.h"

UCLASS()
class UStat : public UObject
{
	GENERATED_BODY()
public:
	UStat();

	UFUNCTION(BlueprintCallable, Category = "Stat")
	double GetValue();

	UFUNCTION(BlueprintCallable, Category = "Stat")
	void SetValue(double newVal);

	UFUNCTION(BlueprintCallable, Category = "Stat")
	FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Stat")
	void SetName(FString newVal);

	FORCEINLINE		UStat&		operator+(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value + value;
		}

		return *nstat;
	}

	FORCEINLINE		UStat&		operator+=(UStat &astat)
	{
		value += astat.value;

		return *this;
	}
	FORCEINLINE		UStat&		operator-(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value - value;
		}

		return *nstat;
	}

	FORCEINLINE		UStat&		operator-=(UStat &astat)
	{
		value -= astat.value;

		return *this;
	}
	FORCEINLINE		UStat&		operator*(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value * value;
		}

		return *nstat;
	}

	FORCEINLINE		UStat&		operator*=(UStat &astat)
	{
		value *= astat.value;

		return *this;
	}
	FORCEINLINE		UStat&		operator/(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value / value;
		}

		return *nstat;
	}

	FORCEINLINE		UStat&		operator/=(UStat &astat)
	{
		value /= astat.value;

		return *this;
	}

private:
	double value;
	FString name;
};
