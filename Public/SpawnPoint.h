///////////////////////////////////////////////////////////
//  SpawnPoint.h
//  Implementation of the Class ASpawnPoint
//  Created on:      06-May-2015 22:21:31
//  Original author: sam
///////////////////////////////////////////////////////////

#pragma once
#include "Engine/TargetPoint.h"
#include "SpawnPoint.generated.h"

UCLASS()
class MUTAGEN_API ASpawnPoint : public ATargetPoint
{
	GENERATED_UCLASS_BODY()
public:

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
		void SetCharacterClass(TSubclassOf<AMutagenCharacter> newClass);

	UFUNCTION()
	void EntityDied(AMutagenCharacter* entityInvolved);

	FTimerHandle spawnTimer;

private:
	float cooldown;
	bool onCooldown;

	UPROPERTY(EditAnywhere, Category = "Spawn Point")
	TSubclassOf<AMutagenCharacter> characterClass;

	UPROPERTY(VisibleAnywhere, Category = "Spawn Point")
	UCapsuleComponent* spawnCapsule;
};
