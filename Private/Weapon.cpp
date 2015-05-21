///////////////////////////////////////////////////////////
//  Weapon.cpp
//  Implementation of the Class AWeapon
//  Created on:      04-May-2015 12:37:34
//  Original author: sam
///////////////////////////////////////////////////////////
#include "Mutagen.h"
#include "Weapon.h"


AWeapon::AWeapon(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer){
	weaponMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("WeaponMesh"));
	weaponMesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	weaponMesh->bChartDistanceFactor = true;
	weaponMesh->bReceivesDecals = false;
	weaponMesh->CastShadow = true;
	weaponMesh->SetCollisionObjectType(ECC_WorldDynamic);
	weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	weaponMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	RootComponent = weaponMesh;

	bPlayingAttackAnim = false;
	SetEquiped(false);
	bWantsToAttack = false;
	bPendingEquip = false;
	SetCurrentState(EWeaponState::Idle);

	LastAttackTime = 0.0f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	//bReplicateInstigator = true;
	bNetUseOwnerRelevancy = true;
}


void AWeapon::UnEquip(AMutagenCharacter* entity) {
	DetachMeshFromPawn();
	SetEquiped(true);
	StopAttack();

	if (bPendingEquip)
	{
		StopWeaponAnimation(equipAnimation);
		bPendingEquip = false;

		//GetWorldTimerManager().ClearTimer(this, &AWeapon::OnEquipFinished);
		GetWorldTimerManager().ClearTimer(equipTimerHandle);
	}

	DetermineWeaponState();
}

void AWeapon::Equip(AMutagenCharacter* entity){
	AttachMeshToPawn();

	bPendingEquip = true;
	DetermineWeaponState();

	float duration = PlayWeaponAnimation(equipAnimation);
	if (duration <= 0.0f)
	{
		duration = 0.5f;
	}
	EquipStartedTime = GetWorld()->GetTimeSeconds();
	EquipDuration = duration;

	//GetWorldTimerManager().SetTimer(this, &AWeapon::OnEquipFinished, duration, false);
	GetWorldTimerManager().SetTimer(equipTimerHandle, this, &AWeapon::OnEquipFinished, duration, false);

	if (GetItemOwner() && GetItemOwner()->IsLocallyControlled())
	{
		//play weapon equip sound
	}
}

/**
 * [local + server] handle weapon attack
 */
FHitResult AWeapon::WeaponTrace(const FVector& TraceFrom, const FVector& TraceTo) const
{
	static FName WeaponAttackTag = FName(TEXT("WeaponTrace"));

	FCollisionQueryParams TraceParams(WeaponAttackTag, true, Instigator);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingle(Hit, TraceFrom, TraceTo, ECollisionChannel::ECC_Vehicle, TraceParams);

	return Hit;
}


void AWeapon::AttachMeshToPawn(){
	if (GetItemOwner())
	{
		DetachMeshFromPawn();

		FName AttachPoint; //= GetWeaponAttachPoint()
		USkeletalMeshComponent* pawnmesh = GetItemOwner()->GetMesh();
		weaponMesh->AttachTo(pawnmesh, AttachPoint);
	}
}

void AWeapon::DetachMeshFromPawn(){
	weaponMesh->DetachFromParent();
	weaponMesh->SetHiddenInGame(true);
}

UAudioComponent* AWeapon::PlayWeaponSound(USoundCue* sound){
	UAudioComponent* AC = NULL;
	if (sound && GetItemOwner())
	{
		//AC = UGameplayStatics::PlaySoundAttached(sound, GetItemOwner()->GetRootComponent());
	}

	return AC;
}


float AWeapon::PlayWeaponAnimation(UAnimMontage* animation){
	float duration = 0.0f;
	if (GetItemOwner() && animation)
	{
		duration = GetItemOwner()->PlayAnimMontage(animation);
	}

	return duration;
}


float AWeapon::StopWeaponAnimation(UAnimMontage* animation){

	float duration = 0.0f;
	if (GetItemOwner() && animation)
	{
		duration = GetItemOwner()->PlayAnimMontage(animation);
	}

	return duration;
}

void AWeapon::OnEquipFinished(){
	AttachMeshToPawn();

	SetEquiped(true);
	bPendingEquip = false;

	DetermineWeaponState();
}


void AWeapon::DetermineWeaponState(){
	EWeaponState::Type NewState = EWeaponState::Idle;

	if (IsEquiped())
	{
		if (bWantsToAttack && CanAttack())
		{
			NewState = EWeaponState::Attacking;
		}
	}
	else if (bPendingEquip)
	{
		NewState = EWeaponState::Equipping;
	}

	SetCurrentState(NewState);
}


void AWeapon::OnAttackStarted(){

}


void AWeapon::OnAttackFinished(){
	bReattacking = false;
}

void AWeapon::PlayAttackAnimation(){

}


void AWeapon::StopAttackAnimation(){

}

void AWeapon::PostInitializeComponents(){
	Super::PostInitializeComponents();
	DetachMeshFromPawn();
}

bool AWeapon::CanAttack() {
	bool bCanAttack = false;

	if (GetItemOwner()){
		bCanAttack = true;
	}

	bool bStatesOK = ((currentState == EWeaponState::Idle) || (currentState == EWeaponState::Attacking));

	return (bCanAttack && bStatesOK);
}

UStat* AWeapon::GetWeaponDamage(){
	return weaponDamage;
}


void AWeapon::SetWeaponDamage(UStat* newVal){
	weaponDamage = newVal;
}

UStat* AWeapon::GetWeaponRange(){
	return weaponRange;
}


void AWeapon::SetWeaponRange(UStat* newVal){
	weaponRange = newVal;
}


/**
 * UFUNCTION(BlueprintCallable, Category = "Weapon")
 */
TEnumAsByte<EWeaponState::Type> AWeapon::GetCurrentState(){
	return currentState;
}

/**
 * UFUNCTION(BlueprintCallable, Category = "Weapon")
 */
void AWeapon::SetCurrentState(EWeaponState::Type newVal){

	const EWeaponState::Type PrevState = currentState;

	if (PrevState == EWeaponState::Attacking && newVal != EWeaponState::Attacking)
	{
		OnAttackFinished();
	}
	else {
		OnAttackStarted();
	}

	currentState = newVal;
}


void AWeapon::StopAttack(){
	if (Role < ROLE_Authority)
	{
		ServerStopAttack();
	}

	if (bWantsToAttack)
	{
		bWantsToAttack = false;
		DetermineWeaponState();
	}
}

void AWeapon::ServerStopAttack(){

}


void AWeapon::StartAttack(){

}


bool AWeapon::IsOneHanded(){
	return oneHanded;
}


void AWeapon::SetOneHanded(bool newVal){
	oneHanded = newVal;
}

EWeaponType::WeaponType AWeapon::GetCurrentWeaponType(){
	return currentWeaponType;
}


void AWeapon::SetCurrentWeaponType(EWeaponType::WeaponType newVal){
	currentWeaponType = newVal;
}
