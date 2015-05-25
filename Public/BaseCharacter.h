// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Array.h"
#include "BaseCharacter.generated.h"

class UInventory;
class UPassive;
class UStat;
class UQuest;
class AMutagenPlayer;
class AItem;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDeathEvent, ABaseCharacter*, entityInvolved);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterPickupItem, ABaseCharacter*, entityInvolved, AItem*, item);

UCLASS()
class MUTAGEN_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
protected:

	/** called when the character's health reaches 0 */
	virtual void Died();
public:
	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

	//----------------Events-------------------------

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FCharacterDeathEvent OnCharacterDeathEvent;

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FCharacterPickupItem OnCharacterPickupItem;


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
	
	//----------------Base Stats-------------------------

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(float newVal);

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetMaxHealth(float newVal);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void SetMaxStamina(float newVal);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		float GetMaxStamina();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		float GetCurrentStamina();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void SetCurrentStamina(float newVal);

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

	bool InteractWith(AMutagenPlayer* player);
	void InitiateInteraction(AMutagenPlayer* player);
	UQuest* AcceptQuest();
	AItem* AddItem(AItem* item);

private:
	float currentHealth;
	float currentStamina;
	UInventory* inventory;

	TArray<UPassive*> passives;
	TArray<UStat*> unmodifiedStats;
	TArray<UStat*> modifiedStats;

	UPROPERTY(EditDefaultsOnly, Category = Name)
		FString characterName;
};
