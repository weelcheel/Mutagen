// Fill out your copyright notice in the Description page of Project Settings.

#include "Mutagen.h"
#include "MutagenPlayerController.h"
#include "Quest.h"
#include "Engine.h"
#include "UnrealNetwork.h"
#include "MutagenPlayer.h"

AMutagenPlayerController::AMutagenPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	sightDistance = 710.f;
}

void AMutagenPlayerController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
}

void AMutagenPlayerController::AddQuest(UQuest* newQuest)
{
	quests.AddUnique(newQuest);
}

void AMutagenPlayerController::GetQuests(TArray<UQuest*>& outArray)
{
	outArray = quests;
}

void AMutagenPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMutagenPlayerController, quests);
}

AActor* AMutagenPlayerController::GetActorCurrentlyLookingAt()
{
	const AMutagenPlayer* playerCharacter = Cast<AMutagenPlayer>(GetCharacter());
	if (!playerCharacter)
		return NULL;

	const FVector startTrace = playerCharacter->followCamera->GetComponentLocation(); //start location of the trace
	const FRotator traceDirection = ControlRotation; //use the controller rotation for direction not character's
	const FVector endTrace = startTrace + (traceDirection.Vector() * sightDistance);

	FHitResult traceHit;
	FCollisionQueryParams collision;

	GetWorld()->LineTraceSingle(traceHit, startTrace, endTrace, ECC_Camera, collision);

	AActor* sightActor = traceHit.GetActor();
	
	return sightActor;
}