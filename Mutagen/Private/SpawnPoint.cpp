///////////////////////////////////////////////////////////
//  SpawnPoint.cpp
//  Implementation of the Class ASpawnPoint
//  Created on:      06-May-2015 22:21:31
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "SpawnPoint.h"




/**
 * Sets default values for this actor's properties
 */
ASpawnPoint::ASpawnPoint(const FObjectInitializer& ObjectInitializer){

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;
}


/**
 * Called when the game starts or when spawned
 */
void ASpawnPoint::BeginPlay(){
	Super::BeginPlay();
}


/**
 * Called every frame
 */
void ASpawnPoint::Tick(float DeltaSeconds){
	Super::Tick(DeltaSeconds);
}


float ASpawnPoint::GetCooldown(){
	return cooldown;
}


void ASpawnPoint::SetCooldown(float newVal){
	cooldown = newVal;
}


bool ASpawnPoint::IsOnCooldown(){
	return onCooldown;
}


void ASpawnPoint::SetOnCooldown(bool newVal){
	onCooldown = newVal;
}