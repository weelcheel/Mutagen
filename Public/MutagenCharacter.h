///////////////////////////////////////////////////////////
//  MutagenCharacter.h
//  Implementation of the Class AMutagenCharacter
//  Created on:      04-May-2015 13:02:59
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "BaseCharacter.h"
#include "MutagenCharacter.generated.h"

class UStat;
class UInventory;
class USkill;
class AWeapon;
class UPassive;
class AItem;


UCLASS(Blueprintable)
/**
 * #include "Skill.h" #include "UQuest.h"
 */
class AMutagenCharacter : public ABaseCharacter
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

	/** variable that contains the character's in-game name (useful for UI) */




public:
	AMutagenCharacter(const FObjectInitializer& ObjectInitializer);

	/**Calculate defensive damage modifers and inflict damage and .*/
	UFUNCTION(BlueprintCallable, Category = "Damage")
		virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	

	//----------------Weapon-------------------------

	/**
	 * Calculate defensive damage modifers and inflict damage and .
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StartWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StopWeaponAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		TArray<AWeapon*> GetEquipedWeapons();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetEquipedWeapons(TArray<AWeapon*> newVal);


	//----------------Skills-------------------------

	UFUNCTION(BlueprintCallable, Category = "Skills")
		TArray<USkill*> GetSkills();

	UFUNCTION(BlueprintCallable, Category = "Skills")
		void SetSkills(TArray<USkill*> newVal);



	UFUNCTION(BlueprintImplementableEvent, Category = HUD)
		virtual void PostRenderFor(class APlayerController* PC, class UCanvas* Canvas, FVector CameraPosition, FVector CameraDir);
private:
	/** current attacking state */
	uint8 bWantsToAttack : 1;

	TArray<USkill*> skills;
	TArray<AWeapon*> equipedWeapons;
};
