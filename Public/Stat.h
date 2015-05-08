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

UCLASS(Blueprintable)
class UStat : public UObject
{
	GENERATED_BODY()
public:
	UStat();

	UFUNCTION(BlueprintCallable, Category = "Stat")
		float GetValue();

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetValue(float newVal);

	UFUNCTION(BlueprintCallable, Category = "Stat")
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetName(FString newVal);

	UFUNCTION(BlueprintCallable, Category = "Stat")
	static UStat* CreateStat(FString name, float value);

	FORCEINLINE UStat& operator+(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value + value;
		}

		return *nstat;
	}

	FORCEINLINE UStat& operator+=(UStat &astat)
	{
		value += astat.value;

		return *this;
	}
	FORCEINLINE UStat& operator-(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value - value;
		}

		return *nstat;
	}

	FORCEINLINE UStat& operator-=(UStat &astat)
	{
		value -= astat.value;

		return *this;
	}
	FORCEINLINE UStat& operator*(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value * value;
		}

		return *nstat;
	}

	FORCEINLINE UStat& operator*=(UStat &astat)
	{
		value *= astat.value;

		return *this;
	}

	FORCEINLINE UStat& operator/(UStat &astat)
	{
		UStat* nstat = ConstructObject<UStat>(UStat::StaticClass());
		if (nstat)
		{
			nstat->value = astat.value / value;
		}

		return *nstat;
	}

	FORCEINLINE UStat& operator/=(UStat &astat)
	{
		value /= astat.value;

		return *this;
	}



private:
	float value;
	FString name;
};
