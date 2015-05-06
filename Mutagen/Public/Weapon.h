///////////////////////////////////////////////////////////
//  Weapon.h
//  Implementation of the Class AWeapon
//  Created on:      04-May-2015 12:37:34
//  Original author: sam
///////////////////////////////////////////////////////////

namespace EWeaponState
{
	UENUM(BlueprintType)
	enum Type
	{
		Idle,
		Attacking,
		Recharging,
		Equipping,
		Unequiping,
	};
}

#pragma once
#include "Item.h"
#include "Stat.h"
#include "Equipable.h"
#include "Weapon.generated.h"

UCLASS(Blueprintable)
class AWeapon : public AItem, public Equipable
{
	GENERATED_BODY()

public:
	AWeapon(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void UnEquip(AMutagenCharacter* entity);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void Equip(AMutagenCharacter* entity);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void OnEquipFinished();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		UStat* GetWeaponDamage();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetWeaponDamage(UStat* newVal);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		UStat* GetWeaponRange();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetWeaponRange(UStat* newVal);

	void PostInitializeComponents();
	/**
	 * current weapon state
	 */
	//UFUNCTION(BlueprintCallable, Category = "Weapon")
		TEnumAsByte<EWeaponState::Type> GetCurrentState();

	/**
	* current weapon state
	*/
	//UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetCurrentState(EWeaponState::Type newVal);

	void DetermineWeaponState();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void AttachMeshToPawn();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void DetachMeshFromPawn();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		UAudioComponent* PlayWeaponSound(USoundCue* sound);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		float PlayWeaponAnimation(UAnimMontage* animation);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		float StopWeaponAnimation(UAnimMontage* animation);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PlayAttackAnimation();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StopAttackAnimation();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void OnAttackStarted();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void OnAttackFinished();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		bool CanAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StopAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void ServerStopAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void StartAttack();
private:
	UStat* weaponDamage;
	UStat* weaponRange;

	/** fighting audio */
	UPROPERTY(Transient)
		UAudioComponent* attackAudio;

	/**equip anim for Character mesh*/
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* equipAnimation;

	/**attack anim for Character mesh*/
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* attackAnimation;

	/** is attack animation playing? */
	uint32 bPlayingAttackAnim : 1;

	/** is weapon attack active? */
	uint32 bWantsToAttack : 1;

	/** is equip animation playing? */
	uint32 bPendingEquip : 1;

	/** weapon is reattacking */
	uint32 bReattacking;

	/** current weapon state */
	TEnumAsByte<EWeaponState::Type> currentState;

	/** time of last successful weapon attack */
	float LastAttackTime;

	/** last time when this weapon was switched to */
	float EquipStartedTime;

	/** how much time weapon needs to be equipped */
	float EquipDuration;

	/**Weapon mesh.*/
	USkeletalMeshComponent* weaponMesh;
protected:

	/**
	* [local + server] handle weapon attack
	*/
	UFUNCTION(BlueprintCallable, Category = Functionality)
		FHitResult WeaponTrace(const FVector& TraceFrom, const FVector& TraceTo) const;
};
