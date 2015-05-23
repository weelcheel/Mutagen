///////////////////////////////////////////////////////////
//  SpawnPoint.h
//  Implementation of the Class ASpawnPoint
//  Created on:      06-May-2015 22:21:31
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "SpawnPoint.generated.h"

UCLASS(Blueprintable)
class MUTAGEN_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
public:
	/**
	 * Sets default values for this actor's properties
	 */
	ASpawnPoint(const FObjectInitializer& ObjectInitializer);
	/**
	 * Called when the game starts or when spawned
	 */
	virtual void BeginPlay() override;
	/**
	 * Called every frame
	 */
	virtual void Tick(float DeltaSeconds) override;


	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		float GetCooldown();

	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		void SetCooldown(float newVal);

	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		bool IsOnCooldown();

	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		void SetOnCooldown(bool newVal);

	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		void Spawn();

	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		UClass* GetCharacterClass();

	UFUNCTION(BlueprintCallable, Category = "Spawn Point")
		void SetCharacterClass(UClass* newVal);

	void EntityDied(ABaseCharacter* entityInvolved);

private:
	float cooldown;
	bool onCooldown;
	UClass* characterClass = AMutagenCharacter::StaticClass();
};
