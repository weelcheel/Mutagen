///////////////////////////////////////////////////////////
//  MutagenCharacter.h
//  Implementation of the Class AMutagenCharacter
//  Created on:      04-May-2015 13:02:59
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "GameFramework/Character.h"
#include "MutagenCharacter.generated.h"

class UStat;
class UInventory;
class USkill;
class AWeapon;
class UPassive;
class AItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDeathEvent, AMutagenCharacter*, entityInvolved);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterPickupItem, AMutagenCharacter*, entityInvolved, AItem*, item);

UCLASS(Blueprintable)
/**
 * #include "Skill.h" #include "UQuest.h"
 */
class AMutagenCharacter : public ACharacter
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

public:
	AMutagenCharacter(const FObjectInitializer& ObjectInitializer);

	/**Calculate defensive damage modifers and inflict damage and .*/
	UFUNCTION(BlueprintCallable, Category = "Damage")
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	//----------------Events-------------------------

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FCharacterDeathEvent OnCharacterDeathEvent;

	UPROPERTY(BlueprintAssignable, Category = "Events")
		FCharacterPickupItem OnCharacterPickupItem;

	/**
	 * Calculate defensive damage modifers and inflict damage and .
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StartWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StopWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		int32 GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Health")
		int32 GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetMaxHealth(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		UInventory* GetInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void SetInventory(UInventory* newVal);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		TArray<UStat*> GetUnmodifiedStats();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetUnmodifiedStats(TArray<UStat*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		TArray<UStat*> GetModifiedStats();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetModifiedStats(TArray<UStat*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Skills")
		TArray<USkill*> GetSkills();

	UFUNCTION(BlueprintCallable, Category = "Skills")
		void SetSkills(TArray<USkill*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		TArray<AWeapon*> GetEquipedWeapons();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetEquipedWeapons(TArray<AWeapon*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
		int32 GetStamina();

	/**
	 * Calculate defensive damage modifers and inflict damage and .
	 */
	UFUNCTION(BlueprintCallable, Category = "Stamina")
		void SetStamina(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Passives")
		TArray<UPassive*> GetPassives();

	UFUNCTION(BlueprintCallable, Category = "Passives")
	void SetPassives(TArray<UPassive*> newVal);

	UStat* GetModifiedStat(FString name);
	UStat* GetModifiedStat(UStat& inStat);
	void ModifyStat(UStat& inStat);
	void AddStat(UStat& inStat);
	void AddStat(FString name, float value);
	UStat* GetUnModifiedStat(FString name);
private:
	int32 maxHealth;
	int32 currentHealth;

	/** current attacking state */
	uint8 bWantsToAttack : 1;

	UInventory* inventory;

	TArray<UStat*> unmodifiedStats;
	TArray<UStat*> modifiedStats;

	TArray<USkill*> skills;

	TArray<AWeapon*> equipedWeapons;

	int32 stamina;
	TArray<UPassive*> passives;
};