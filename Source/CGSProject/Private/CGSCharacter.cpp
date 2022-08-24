// Fill out your copyright notice in the Description page of Project Settings.


#include "CGSCharacter.h"
#include "ButtonToUnlockDoor.h"

// Sets default values
ACGSCharacter::ACGSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACGSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACGSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACGSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACGSCharacter::OpenDoor() {
	if (Button.IsValid()) {
		Button->OpenTheDoor();
	}
}
