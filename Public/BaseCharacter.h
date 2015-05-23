// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Array.h"
#include "BaseCharacter.generated.h"

class UInventory;
class UPassive;
class UStat;

UCLASS()
class MUTAGEN_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, Category = "Stat Names")
		FString maxHealthName;

	UPROPERTY(BlueprintReadWrite, Category = "Stat Names")
		FString staminaName;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		UInventory* GetInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void SetInventory(UInventory* newVal);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetCharacterName(FString newName);

	UFUNCTION(BlueprintCallable, Category = "Name")
		FString GetCharacterName();

	UFUNCTION(BlueprintCallable, Category = "Health")
		int32 GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Health")
		int32 GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetMaxHealth(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void SetStamina(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		int32 GetStamina();


	//----------------Stats-------------------------

	UFUNCTION(BlueprintCallable, Category = "Stats")
		TArray<UStat*> GetUnmodifiedStats();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetUnmodifiedStats(TArray<UStat*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		TArray<UStat*> GetModifiedStats(bool update);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetModifiedStats(TArray<UStat*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* GetModifiedStatByName(FString name);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* GetModifiedStat(UStat* inStat);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* ModifyStat(UStat* inStat);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* AddStat(UStat* inStat);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* AddNewStat(FString name, float value);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* GetUnModifiedStat(FString name);

	UFUNCTION(BlueprintCallable, Category = "Passives")
		TArray<UPassive*> GetPassives();

	UFUNCTION(BlueprintCallable, Category = "Passives")
		void SetPassives(TArray<UPassive*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Passives")
		UPassive* AddPassive(UPassive* newPassive);

private:
	int32 currentHealth;
	int32 currentStamina;
	UInventory* inventory;

	TArray<UPassive*> passives;
	TArray<UStat*> unmodifiedStats;
	TArray<UStat*> modifiedStats;

	UPROPERTY(EditDefaultsOnly, Category = Name)
		FString characterName;
};
