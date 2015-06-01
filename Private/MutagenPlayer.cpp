// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Mutagen.h"
#include "MutagenPlayer.h"
#include "Bag.h"
#include "Quest.h"
#include "MutagenProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AMutagenPlayer

AMutagenPlayer::AMutagenPlayer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	cameraBoom = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	cameraBoom->AttachTo(RootComponent);
	cameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	cameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	followCamera = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FollowCamera"));
	followCamera->AttachTo(cameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	followCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMutagenPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("WeaponAttack", IE_Pressed, this, &AMutagenCharacter::StartWeaponAttack);
	InputComponent->BindAction("WeaponAttack", IE_Released, this, &AMutagenCharacter::StopWeaponAttack);

	//InputComponent->BindAction("PlayerUse", IE_Pressed, this, &ADFPlayerCharacter::PlayerUse);
	//InputComponent->BindAction("SkillUse", IE_Pressed, this, &ADFPlayerCharacter::SkillUse);

	InputComponent->BindAxis("MoveForward", this, &AMutagenPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMutagenPlayer::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AMutagenPlayer::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AMutagenPlayer::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &AMutagenPlayer::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AMutagenPlayer::TouchStopped);
}

/**
 * Handler for when a touch input begins.
 */
void AMutagenPlayer::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

/**
 * Handler for when a touch input stops.
 */
void AMutagenPlayer::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

/**
 * Handles moving forward/backward
 */
void AMutagenPlayer::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

/**
 * Handles stafing movement, left and right
 */
void AMutagenPlayer::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

/**
 * Called via input to turn at a given rate.
 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
 */
void AMutagenPlayer::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

/**
 * Called via input to turn look up/down at a given rate.
 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
 */
void AMutagenPlayer::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


//void AMutagenPlayer::GetLifetimeReplicatedProps(TArray< class FLifetimeProperty > & OutLifetimeProps) const
//{
//	/*Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//	DOREPLIFETIME(ADigitalForgeCharacter, CurrentWeapon);
//	DOREPLIFETIME(ADigitalForgeCharacter, Health);
//	DOREPLIFETIME(ADigitalForgeCharacter, BaseStats);*/
//}



TArray<UBag*> AMutagenPlayer::GetBags(){

	return bags;
}


void AMutagenPlayer::SetBags(TArray<UBag*> newVal){

	bags = newVal;
}


void AMutagenPlayer::OpenInventory(){

}


AItem* AMutagenPlayer::SelectInventoryItem(){

	return  NULL;
}


bool AMutagenPlayer::ExchangeItems(AItem* itemA, AItem* itemB){

	return false;
}


bool AMutagenPlayer::OpenQuestList(){
	return false;
}


void AMutagenPlayer::SelectQuest(UQuest* questSelected){
	selectedQuest = questSelected;
}


void AMutagenPlayer::AbandonQuest(UQuest* quest){
	GetSelectedQuest() != NULL ? GetSelectedQuest()->AbandonQuest() : true;
}


UQuest* AMutagenPlayer::GetSelectedQuest(){
	return selectedQuest;
}


bool AMutagenPlayer::OpenSkillTree(){

	return false;
}