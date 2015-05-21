// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "BaseCharacter.h"
#include "Inventory.h" 
#include "Skill.h"
#include "Stat.h"
#include "Passive.h"

// Sets default values
ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetCurrentHealth(100);
	SetMaxHealth(100);
	SetModifiedStats(*new TArray<UStat*>());
	SetUnmodifiedStats(*new TArray<UStat*>());
	SetInventory(ConstructObject<UInventory>(UInventory::StaticClass()));

	maxHealthName = "MaxHealth";
	staminaName = "Stamina";
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


/* This method is used to get the actual value of stats
This currenty checks all passives to see if the stat needs to be change, + or -
If the stat isn't found then it will default to 0 and the passives could make it -
*/
UStat* ABaseCharacter::GetModifiedStatByName(FString name){
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
			ModifyStat(&tempStat);
			break;
		}
	}
	return &tempStat;
}

/* Checks all stats and modifies them with the current passives, returns the results */
TArray<UStat*> ABaseCharacter::GetModifiedStats(bool update = false){
	if (update) {
		TArray<UStat*> tempStats = *new TArray<UStat*>();

		for (UStat* stat : GetUnmodifiedStats()){
			//Create a temp stat to add to the array
			UStat& tempStat = *ConstructObject<UStat>(UStat::StaticClass());

			// Copy the values
			tempStat += *stat;
			tempStat.SetName(stat->GetName());

			// Modify the stat then add it to the array
			tempStats.Add(GetModifiedStat(&tempStat));
		}

		// Set the ModifiedStats array to this, to keep a record of it
		// GetModifiedStats() should be called every time a pssive is added, removed, changed etc to keep the array up to date
		SetModifiedStats(tempStats);
	}
	return modifiedStats;
}

/* This is used to get a modified version of a stat  */
UStat* ABaseCharacter::GetModifiedStat(UStat* inStat){
	ModifyStat(inStat);
	return inStat;
}

UStat* ABaseCharacter::GetUnModifiedStat(FString name){
	// Look through are current unmodified stats to see if this stat exists
	for (UStat* stat : GetUnmodifiedStats()){

		// Does the stat matches the stat we're looking for 
		if (stat->GetName().Equals(name)) {
			return stat;
		}
	}
	return NULL;
}


/* Loops through all passives getting them to manipulate the stat, if at all */
UStat* ABaseCharacter::ModifyStat(UStat* inStat){
	for (UPassive* passive : GetPassives()) {
		passive->ModifyStat(*inStat);
	}

	return inStat;
}


/*Adds a stat to the current unmodifiedStats, if the stat exists then it increases it's value by the in Stats' value */
UStat* ABaseCharacter::AddStat(UStat* inStat){
	UStat* tempStat = GetUnModifiedStat(inStat->GetName());
	if (tempStat != NULL){
		*tempStat += *inStat;
	}
	else {
		unmodifiedStats.Add(inStat);
	}

	return inStat;
}

/*Adds a new stat to unmodifiedStats using ConstructObject and then AddStat */
UStat* ABaseCharacter::AddNewStat(FString name, float value){
	UStat& tempStat = *ConstructObject<UStat>(UStat::StaticClass());

	// Copy the values
	tempStat.SetValue(value);
	tempStat.SetName(name);
	AddStat(&tempStat);

	return &tempStat;
}

UInventory* ABaseCharacter::GetInventory(){
	return inventory;
}

void ABaseCharacter::SetInventory(UInventory* newVal){
	inventory = newVal;
}

TArray<UStat*> ABaseCharacter::GetUnmodifiedStats(){
	return unmodifiedStats;
}

void ABaseCharacter::SetUnmodifiedStats(TArray<UStat*> newVal){
	unmodifiedStats = newVal;
}

void ABaseCharacter::SetModifiedStats(TArray<UStat*> newVal){
	modifiedStats = newVal;
}


int32 ABaseCharacter::GetStamina(){
	return GetModifiedStatByName(staminaName)->GetValue();
}

/**
* Calculate defensive damage modifers and inflict damage and .
*/
void ABaseCharacter::SetStamina(int32 newVal){
	if (GetModifiedStatByName(staminaName)->GetValue() == 0){
		AddNewStat(staminaName, newVal);
	}
}

TArray<UPassive*> ABaseCharacter::GetPassives(){
	return passives;
}


void ABaseCharacter::SetPassives(TArray<UPassive*> newVal){
	passives = newVal;
}

int32 ABaseCharacter::GetCurrentHealth(){
	return currentHealth;
}

void ABaseCharacter::SetCurrentHealth(int32 newVal){
	currentHealth = newVal;
}

int32 ABaseCharacter::GetMaxHealth(){
	return GetModifiedStatByName(maxHealthName)->GetValue();
}

void ABaseCharacter::SetMaxHealth(int32 newVal){
	AddNewStat(maxHealthName, newVal);
}

void ABaseCharacter::SetCharacterName(FString newName)
{
	characterName = newName;
}

FString ABaseCharacter::GetCharacterName()
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
