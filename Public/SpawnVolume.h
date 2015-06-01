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

UCLASS(Blueprintable)
class MUTAGEN_API ASpawnVolume : public AVolume
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Spawn Volume")
		TArray<ASpawnPoint*> GetSpawnPoints();

	UFUNCTION(BlueprintCallable, Category = "Spawn Volume")
		void SetSpawnPoints(TArray<ASpawnPoint*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Spawn Volume")
		void Spawn();



private:

	UPROPERTY(EditAnywhere, Category = "Spawn Point")
	TArray<ASpawnPoint*> spawnPoints;
};
