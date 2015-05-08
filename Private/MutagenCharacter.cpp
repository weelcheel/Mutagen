///////////////////////////////////////////////////////////
//  MutagenCharacter.cpp
//  Implementation of the Class AMutagenCharacter
//  Created on:      04-May-2015 13:02:59
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "MutagenCharacter.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Skill.h"
#include "Stat.h"
#include "Passive.h"

AMutagenCharacter::AMutagenCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){
	SetModifiedStats(*new TArray<UStat*>());
	SetUnmodifiedStats(*new TArray<UStat*>());
	SetEquipedWeapons(*new TArray<AWeapon*>());
	SetSkills(*new TArray<USkill*>());
	SetCurrentHealth(100);
	SetMaxHealth(100);
	SetInventory(ConstructObject<UInventory>(UInventory::StaticClass()));

}

void AMutagenCharacter::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentHealth(GetMaxHealth());

	if (OnCharacterDeathEvent.IsBound()){
		OnCharacterDeathEvent.Broadcast(this);
	}
}

/* This method is used to get the actual value of stats
	This currenty checks all passives to see if the stat needs to be change, + or -
	If the stat isn't found then it will default to 0 and the passives could make it -
	*/
UStat* AMutagenCharacter::GetModifiedStat(FString name){
	// Create a tempory stat to send back
	UStat& tempStat = *ConstructObject<UStat>(UStat::StaticClass());
	tempStat.SetValue(0);
	tempStat.SetName(name);

	// Look through are current unmodified stats to see if this stat exists
	for (UStat* stat : GetUnmodifiedStats()){

		// Does the stat matches the stat we're looking for 
		if (stat->GetName().Equals(name)){
			//Get the correct value for the stat
			tempStat += *stat;

			// Modify the stat with passives
			ModifyStat(tempStat);
			break;
		}
	}


	return &tempStat;
}

/* Checks all stats and modifies them with the current passives, returns the results */
TArray<UStat*> AMutagenCharacter::GetModifiedStats(){
	TArray<UStat*> tempStats = *new TArray<UStat*>();

	for (UStat* stat : GetUnmodifiedStats()){
		//Create a temp stat to add to the array
		UStat& tempStat = *ConstructObject<UStat>(UStat::StaticClass());

		// Copy the values
		tempStat += *stat;
		tempStat.SetName(stat->GetName());

		// Modify the stat then add it to the array
		tempStats.Add(GetModifiedStat(tempStat));
	}

	// Set the ModifiedStats array to this, to keep a record of it
	// GetModifiedStats() should be called every time a pssive is added, removed, changed etc to keep the array up to date
	SetModifiedStats(tempStats);

	return tempStats;
}

/* This is used to get a modified version of a stat  */
UStat* AMutagenCharacter::GetModifiedStat(UStat& inStat){
	ModifyStat(inStat);
	return &inStat;
}

UStat* AMutagenCharacter::GetUnModifiedStat(FString name){
	// Look through are current unmodified stats to see if this stat exists
	for (UStat* stat : GetUnmodifiedStats()){

		// Does the stat matches the stat we're looking for 
		if (stat->GetName().Equals(name)){
			return stat;
		}
	}
	return NULL;
}


/* Loops through all passives getting them to manipulate the stat, if at all */
void AMutagenCharacter::ModifyStat(UStat& inStat){
	for (UPassive* passive : GetPassives()) {
		passive->ModifyStat(inStat);
	}
}


/*Adds a stat to the current unmodifiedStats, if the stat exists then it increases it's value by the in Stats' value */
void AMutagenCharacter::AddStat(UStat& inStat){
	UStat* tempStat = GetUnModifiedStat(inStat.GetName());
	if (tempStat != NULL){
		*tempStat += inStat;
	}
	else {
		unmodifiedStats.Add(&inStat);
	}
}

/*Adds a new stat to unmodifiedStats using ConstructObject and then AddStat */
void AMutagenCharacter::AddStat(FString name, float value){
	UStat& tempStat = *ConstructObject<UStat>(UStat::StaticClass());

	// Copy the values
	tempStat.SetValue(value);
	tempStat.SetName(name);
	AddStat(tempStat);
}


/**
 * Calculate defensive damage modifers and inflict damage and .
 */
float AMutagenCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//@todo: implement all defensive stat modifers

	currentHealth -= Damage;

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


/**
 * Calculate defensive damage modifers and inflict damage and .
 */
void AMutagenCharacter::SetStamina(int32 newVal){
	stamina = newVal;
}

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
