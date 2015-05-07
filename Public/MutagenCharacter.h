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

	/** variable that contains the character's in-game name (useful for UI) */
	UPROPERTY(EditDefaultsOnly, Category=Name)
	FString characterName;

public:
	AMutagenCharacter(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = Name)
	void SetCharacterName(FString newName);

	UFUNCTION(BlueprintCallable, Category = Name)
	FString GetCharacterName();

	/**Calculate defensive damage modifers and inflict damage and .*/
	UFUNCTION(BlueprintCallable, Category = Damage)
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	UFUNCTION(BlueprintCallable, Category = "Attack")
		void StartWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void StopWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Health")
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

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void SetStamina(int32 newVal);

	UFUNCTION(BlueprintImplementableEvent, Category = HUD)
	virtual void PostRenderFor(class APlayerController* PC, class UCanvas* Canvas, FVector CameraPosition, FVector CameraDir);

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