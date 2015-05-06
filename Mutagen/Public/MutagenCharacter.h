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
	UFUNCTION(BlueprintCallable, Category = "Stamina")
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	/**
	 * Calculate defensive damage modifers and inflict damage and .
	 */
	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void StartWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StopWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	int32 GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SetCurrentHealth(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	int32 GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetMaxHealth(int32 newVal);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	UInventory* GetInventory();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetInventory(UInventory* newVal);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		TArray<UStat*> GetUnmodifiedStats();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetUnmodifiedStats(TArray<UStat*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<UStat*> GetModifiedStats();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetModifiedStats(TArray<UStat*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Health")
	TArray<USkill*> GetSkills();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetSkills(TArray<USkill*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Health")
	TArray<AWeapon*> GetEquipedWeapons();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetEquipedWeapons(TArray<AWeapon*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Attack")
	int32 GetStamina();

	/**
	 * Calculate defensive damage modifers and inflict damage and .
	 */
	UFUNCTION(BlueprintCallable, Category = Damage)
	void SetStamina(int32 newVal);

	TArray<UPassive*> GetPassives();
	void SetPassives(TArray<UPassive*> newVal);
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