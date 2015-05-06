///////////////////////////////////////////////////////////
//  SpawnVolume.cpp
//  Implementation of the Class ASpawnVolume
//  Created on:      06-May-2015 22:21:32
//  Original author: sam
///////////////////////////////////////////////////////////

#include "Mutagen.h"
#include "SpawnVolume.h"
#include "SpawnPoint.h"



TArray<ASpawnPoint*> ASpawnVolume::GetSpawnPoints(){
	return spawnPoints;
}


void ASpawnVolume::SetSpawnPoints(TArray<ASpawnPoint*> newVal){
	spawnPoints = newVal;
}