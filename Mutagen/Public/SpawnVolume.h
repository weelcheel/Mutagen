///////////////////////////////////////////////////////////
//  SpawnVolume.h
//  Implementation of the Class ASpawnVolume
//  Created on:      06-May-2015 22:21:31
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "GameFramework/Volume.h"
#include "SpawnVolume.generated.h"

class ASpawnPoint;

UCLASS()
class MUTAGEN_API ASpawnVolume : public AVolume
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Spawn Volume")
		TArray<ASpawnPoint*> GetSpawnPoints();

	UFUNCTION(BlueprintCallable, Category = "Spawn Volume")
		void SetSpawnPoints(TArray<ASpawnPoint*> newVal);

private:
	TArray<ASpawnPoint*> spawnPoints;


};
