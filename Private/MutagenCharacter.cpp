///////////////////////////////////////////////////////////
//  MutagenCharacter.cpp
//  Implementation of the Class AMutagenCharacter
//  Created on:      04-May-2015 13:02:59
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "MutagenCharacter.h"

AMutagenCharacter::AMutagenCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){

}

void AMutagenCharacter::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentHealth(GetMaxHealth());
}


float AMutagenCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//@todo: implement all defensive stat modifers

	currentHealth -= Damage;

	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}


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


int32 AMutagenCharacter::GetCurrentHealth(){
	return currentHealth;
}


void AMutagenCharacter::SetCurrentHealth(int32 newVal){
	currentHealth = newVal;
}


int32 AMutagenCharacter::GetMaxHealth(){
	return maxHealth;
}


void AMutagenCharacter::SetMaxHealth(int32 newVal){
	maxHealth = newVal;
}


UInventory* AMutagenCharacter::GetInventory(){
	return inventory;
}


void AMutagenCharacter::SetInventory(UInventory* newVal){
	inventory = newVal;
}


TArray<UStat*> AMutagenCharacter::GetUnmodifiedStats(){
	return unmodifiedStats;
}


void AMutagenCharacter::SetUnmodifiedStats(TArray<UStat*> newVal){
	unmodifiedStats = newVal;
}

TArray<UStat*> AMutagenCharacter::GetModifiedStats(){
	return modifiedStats;
}


void AMutagenCharacter::SetModifiedStats(TArray<UStat*> newVal){
	modifiedStats = newVal;
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


int32 AMutagenCharacter::GetStamina(){
	return stamina;
}


void AMutagenCharacter::SetStamina(int32 newVal){
	stamina = newVal;
}