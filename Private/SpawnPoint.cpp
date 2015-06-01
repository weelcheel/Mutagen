///////////////////////////////////////////////////////////
//  SpawnPoint.cpp
//  Implementation of the Class ASpawnPoint
//  Created on:      06-May-2015 22:21:31
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "SpawnPoint.h"
#include "BaseCharacter.h"

/**
 * Sets default values for this actor's properties
 */
ASpawnPoint::ASpawnPoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

		spawnCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("spawnCollision"));
		spawnCapsule->InitCapsuleSize(34.0f, 88.0f);
		spawnCapsule->SetCollisionResponseToAllChannels(ECR_Overlap);

		RootComponent = spawnCapsule;
}


/**
 * Called when the game starts or when spawned
 */
void ASpawnPoint::BeginPlay(){
	Super::BeginPlay();
}

void ASpawnPoint::EntityDied(AMutagenCharacter* entityInvolved)
{
	GetWorldTimerManager().SetTimer(spawnTimer, this, &ASpawnPoint::Spawn, GetCooldown());
}

void ASpawnPoint::Spawn()
{
	AMutagenCharacter* entity = GetWorld()->SpawnActor<AMutagenCharacter>(GetCharacterClass(), GetActorLocation(), GetActorRotation());
	if (entity)
	{
		entity->OnCharacterDeathEvent.AddDynamic(this, &ASpawnPoint::EntityDied);
	}
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

UClass* ASpawnPoint::GetCharacterClass()
{
	return characterClass;
}

void ASpawnPoint::SetCharacterClass(TSubclassOf<AMutagenCharacter> newClass)
{
	characterClass = newClass;
}