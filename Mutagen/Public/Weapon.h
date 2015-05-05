///////////////////////////////////////////////////////////
//  Weapon.h
//  Implementation of the Class AWeapon
//  Created on:      04-May-2015 12:37:34
//  Original author: sam
///////////////////////////////////////////////////////////

namespace EWeaponState
{
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

UCLASS()
class AWeapon : public AItem, public Equipable
{
	GENERATED_BODY()

public:
	AWeapon(const FObjectInitializer& ObjectInitializer);

	virtual void UnEquip(AMutagenCharacter* entity);
	virtual void Equip(AMutagenCharacter* entity);
	void OnEquipFinished();

	UStat* GetWeaponDamage();
	void SetWeaponDamage(UStat* newVal);

	UStat* GetWeaponRange();
	void SetWeaponRange(UStat* newVal);

	void PostInitializeComponents();
	/**
	 * current weapon state
	 */
	EWeaponState::Type GetCurrentState();

	/**
	* current weapon state
	*/
	void SetCurrentState(EWeaponState::Type newVal);

	void DetermineWeaponState();

	void AttachMeshToPawn();
	void DetachMeshFromPawn();
	
	UAudioComponent* PlayWeaponSound(USoundCue* sound);

	float PlayWeaponAnimation(UAnimMontage* animation);
	float StopWeaponAnimation(UAnimMontage* animation);

	void PlayAttackAnimation();
	void StopAttackAnimation();

	virtual void OnAttackStarted();
	virtual void OnAttackFinished();

	bool CanAttack();
	void StopAttack();

	void ServerStopAttack();
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
	EWeaponState::Type currentState;

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
