// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "MutagenCharacter.h"
#include "MutagenPlayer.generated.h"

class UInputComponent;
class UBag;
class UQuest;


UCLASS(config = Game, Blueprintable)
class AMutagenPlayer : public AMutagenCharacter
{
	GENERATED_BODY()
private:
	TArray<UBag*> bags;
	UQuest* selectedQuest;

public:
	AMutagenPlayer(const FObjectInitializer& ObjectInitializer);

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* followCamera;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* cameraBoom;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;


protected:

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/*
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	UFUNCTION(BlueprintCallable, Category = "Bags")
		TArray<UBag*> GetBags();

	UFUNCTION(BlueprintCallable, Category = "Bags")
		void SetBags(TArray<UBag*> newVal);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void OpenInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		AItem* SelectInventoryItem();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool ExchangeItems(AItem* itemA, AItem* itemB);

	UFUNCTION(BlueprintCallable, Category = "Quests")
		bool OpenQuestList();

	UFUNCTION(BlueprintCallable, Category = "Quests")
		void SelectQuest(UQuest* questSelected);

	UFUNCTION(BlueprintCallable, Category = "Quests")
		void AbandonQuest(UQuest* quest);

	UFUNCTION(BlueprintCallable, Category = "Quests")
		UQuest* GetSelectedQuest();

	UFUNCTION(BlueprintCallable, Category = "Skills")
		bool OpenSkillTree();
};