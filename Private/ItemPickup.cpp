#include "Mutagen.h"
#include "ItemPickup.h"
#include "Inventory.h"

AItemPickup::AItemPickup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	pickupRadius = CreateDefaultSubobject<USphereComponent>(TEXT("pickupRadius"));
	pickupRadius->InitSphereRadius(115.f);
	pickupRadius->SetCollisionResponseToAllChannels(ECR_Overlap);
	pickupRadius->OnComponentBeginOverlap.AddDynamic(this, &AItemPickup::CharacterInPickupRadius);
	pickupRadius->OnComponentEndOverlap.AddDynamic(this, &AItemPickup::CharacterLeavePickupRadius);
	RootComponent = pickupRadius;

	itemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("itemMesh"));
	itemStaticMesh->SetHiddenInGame(true);

	itemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("itemAnimatedMesh"));
	itemSkeletalMesh->SetHiddenInGame(true);

	ammoLeft = 0;
}

void AItemPickup::CharacterInPickupRadius(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMutagenCharacter* mc = Cast<AMutagenCharacter>(OtherActor);
	if (mc)
	{
		mc->NotifyNearPickup(this);
	}
}

void AItemPickup::CharacterLeavePickupRadius(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMutagenCharacter* mc = Cast<AMutagenCharacter>(OtherActor);
	if (mc)
	{
		mc->NotifyLeavePickup(this);
	}
}

void AItemPickup::CharacterPickup(AMutagenCharacter* pickingCharacter)
{
	//spawn the item to pickup first
	if (!pickingCharacter)
		return;

	AItem* itempickup = GetWorld()->SpawnActor<AItem>(itemClass, pickingCharacter->GetActorLocation(), FRotator::ZeroRotator);
	if (itempickup)
	{
		if (pickingCharacter->GetInventory())
		{
			pickingCharacter->GetInventory()->AddItem(itempickup);
		}
	}
}

void AItemPickup::SetSkeletalMeshComponent(USkeletalMeshComponent* newMesh)
{
	itemSkeletalMesh = newMesh;
}

void AItemPickup::SetWeaponClass(TSubclassOf<AItem> newClass)
{
	itemClass = newClass;
}

void AItemPickup::SetStaticMeshComponent(UStaticMeshComponent* newMesh)
{
	itemStaticMesh = newMesh;
}

USkeletalMeshComponent* AItemPickup::GetSkeletalMeshComponent()
{
	return itemSkeletalMesh;
}

UClass* AItemPickup::GetWeaponClass()
{
	return itemClass;
}

UStaticMeshComponent* AItemPickup::GetStaticMeshComponent()
{
	return itemStaticMesh;
}