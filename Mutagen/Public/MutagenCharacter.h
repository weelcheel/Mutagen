///////////////////////////////////////////////////////////
//  MutagenCharacter.h
//  Implementation of the Class AMutagenCharacter
//  Created on:      04-May-2015 13:02:59
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Inventory.h"
#include "Stat.h"
#include "Skill.h"
#include "Weapon.h"
#include "GameFramework/Character.h"
#include "MutagenCharacter.generated.h"

UCLASS()
class AMutagenCharacter : public ACharacter
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

public:
	AMutagenCharacter(const FObjectInitializer& ObjectInitializer);

	/**Calculate defensive damage modifers and inflict damage and .*/
	UFUNCTION(BlueprintCallable, Category = Damage)
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void StartWeaponAttack();
	void StopWeaponAttack();

	int32 GetCurrentHealth();
	void SetCurrentHealth(int32 newVal);

	int32 GetMaxHealth();
	void SetMaxHealth(int32 newVal);

	UInventory* GetInventory();
	void SetInventory(UInventory* newVal);

	TArray<UStat*> GetUnmodifiedStats();
	void SetUnmodifiedStats(TArray<UStat*> newVal);
	
	TArray<UStat*> GetModifiedStats();
	void SetModifiedStats(TArray<UStat*> newVal);

	TArray<USkill*> GetSkills();
	void SetSkills(TArray<USkill*> newVal);

	TArray<AWeapon*> GetEquipedWeapons();
	void SetEquipedWeapons(TArray<AWeapon*> newVal);

	int32 GetStamina();
	void SetStamina(int32 newVal);
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
};