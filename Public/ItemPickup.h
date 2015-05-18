#pragma once

#include "ItemPickup.generated.h"

UCLASS()
class AItemPickup : public AActor
{
	GENERATED_UCLASS_BODY()

	/** skeletal mesh of the pickup */
	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMeshComponent* itemSkeletalMesh;

	/** static mesh of the pickup */
	UPROPERTY(EditAnywhere, Category = Mesh)
	UStaticMeshComponent* itemStaticMesh;

	/** class of weapon to pickup */
	UPROPERTY(EditAnywhere, Category = Pickup)
	TSubclassOf<AItem> itemClass;

	/** radius of collision where the player can pick this weapon up or grab it's ammo */
	UPROPERTY(EditAnywhere, Category = Pickup)
	USphereComponent* pickupRadius;

	/** amount of ammo this weapon has (if any) */
	UPROPERTY(EditAnywhere, Category = Pickup)
	int32 ammoLeft;

protected:

	/** delegate function for actors that overlap with this actor */
	UFUNCTION()
	void CharacterInPickupRadius(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** delegate for leaving overlapping actors */
	UFUNCTION()
	void CharacterLeavePickupRadius(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:

	/** called whenever a player successfully picks up the item */
	void CharacterPickup(AMutagenCharacter* pickingCharacter);

	//===========================SETTERS/GETTERS=============================

	UFUNCTION(BlueprintCallable, Category = Pickup)
	void SetSkeletalMeshComponent(USkeletalMeshComponent* newMesh);

	UFUNCTION(BlueprintCallable, Category = Pickup)
	void SetWeaponClass(TSubclassOf<AItem> newClass);

	UFUNCTION(BlueprintCallable, Category = Pickup)
	void SetStaticMeshComponent(UStaticMeshComponent* newMesh);

	UFUNCTION(BlueprintCallable, Category = Pickup)
	USkeletalMeshComponent* GetSkeletalMeshComponent();

	UFUNCTION(BlueprintCallable, Category = Pickup)
	UClass* GetWeaponClass();

	UFUNCTION(BlueprintCallable, Category = Pickup)
	UStaticMeshComponent* GetStaticMeshComponent();

	/** display our info to the HUD */
	UFUNCTION(BlueprintImplementableEvent, Category = HUD)
	virtual void PostRenderFor(class APlayerController* PC, class UCanvas* Canvas, FVector CameraPosition, FVector CameraDir) override;
};