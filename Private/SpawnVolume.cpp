///////////////////////////////////////////////////////////
//  SpawnVolume.cpp
//  Implementation of the Class ASpawnVolume
//  Created on:      06-May-2015 22:21:32
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "SpawnVolume.h"
#include "SpawnPoint.h"

ASpawnVolume::ASpawnVolume(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TArray<ASpawnPoint*> ASpawnVolume::GetSpawnPoints(){
	return spawnPoints;
}


void ASpawnVolume::SetSpawnPoints(TArray<ASpawnPoint*> newVal){
	spawnPoints = newVal;
}

void ASpawnVolume::Spawn()
{
	for (ASpawnPoint* spawnPoint : spawnPoints)
	{
		if (spawnPoint)
			spawnPoint->Spawn();
	}
}

void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*>& tempActors = *new TArray<AActor*>();

	GetOverlappingActors(tempActors, ASpawnPoint::StaticClass());

	for (AActor* temp : tempActors)
	{
		ASpawnPoint* sp = Cast<ASpawnPoint>(temp);
		if (sp)
		{
			spawnPoints.Add(sp);
		}
	}
}