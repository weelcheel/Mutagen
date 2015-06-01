///////////////////////////////////////////////////////////
//  MutagenCharacter.cpp
//  Implementation of the Class AMutagenCharacter
//  Created on:      04-May-2015 13:02:59
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "MutagenCharacter.h"
#include "Weapon.h"


AMutagenCharacter::AMutagenCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){
	SetEquipedWeapons(*new TArray<AWeapon*>());
	SetSkills(*new TArray<USkill*>());
}

void AMutagenCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetCurrentHealth(GetMaxHealth());
	}


/**
 * Calculate defensive damage modifers and inflict damage and .
 */
float AMutagenCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//@todo: implement all defensive stat modifers

	if (GetCurrentHealth() > 0) {
		SetCurrentHealth(GetCurrentHealth() - Damage);

		if (GetCurrentHealth() <= 0)
	{
		Died();
	}
	}

	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

/**
 * Calculate defensive damage modifers and inflict damage and .
 */
void AMutagenCharacter::StartWeaponAttack(){
	if (!bWantsToAttack)
	{
		bWantsToAttack = true;
		UE_LOG(LogTemp, Warning, TEXT("Starting weapona attack!"));

		for (AWeapon* weapon : equipedWeapons){
			if (weapon)
			{
				weapon->StartAttack();
			}
		}
	}
}

void AMutagenCharacter::StopWeaponAttack(){
	if (bWantsToAttack)
	{
		bWantsToAttack = false;
		UE_LOG(LogTemp, Warning, TEXT("Stopping weapona attack!"));

		for (AWeapon* weapon : equipedWeapons){
			if (weapon)
			{
				weapon->StopAttack();
			}
}
}
}

TArray<USkill*> AMutagenCharacter::GetSkills(){
	return skills;
}

void AMutagenCharacter::SetSkills(TArray<USkill*> newVal){
	skills = newVal;
}

TArray<AWeapon*> AMutagenCharacter::GetEquipedWeapons(){
	return equipedWeapons;
}

void AMutagenCharacter::SetEquipedWeapons(TArray<AWeapon*> newVal){
	equipedWeapons = newVal;
}

bool AMutagenCharacter::AddSkill(USkill* newSkill){
	skills.Add(newSkill);
	return true;
}


bool AMutagenCharacter::ActivateSkill(USkill* skill){

void AMutagenCharacter::SetCharacterName(FString newName)
{
	characterName = newName;
}

FString AMutagenCharacter::GetCharacterName()
{
	if (GetController())
	{
		// get the player name instead of the character name
		return "Player";
	}
	else
	{
		return characterName;
	}
}

TArray<UPassive*> AMutagenCharacter::GetPassives(){

	return passives;
}


void AMutagenCharacter::SetPassives(TArray<UPassive*> newVal){

	passives = newVal;
}

void AMutagenCharacter::Died()
{

}

void AMutagenCharacter::NotifyNearPickup(AItemPickup* nearPickup)
{
	APlayerController* pc = Cast<APlayerController>(GetController());
	if (pc && pc->GetHUD())
	{
		pc->GetHUD()->AddPostRenderedActor(nearPickup);
	}
}

void AMutagenCharacter::NotifyLeavePickup(AItemPickup* leavingPickup)
{
	APlayerController* pc = Cast<APlayerController>(GetController());
	if (pc && pc->GetHUD())
	{
		pc->GetHUD()->RemovePostRenderedActor(leavingPickup);
	}
}