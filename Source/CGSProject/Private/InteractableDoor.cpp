// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableDoor.h"
#include "DoorInteractionComponent.h"

AInteractableDoor::AInteractableDoor() {

	DoorInteractionComponent = CreateDefaultSubobject<UDoorInteractionComponent>(TEXT("DoorInteractionComponent"));
}

void AInteractableDoor::OpenTheDoor()
{
	if (DoorInteractionComponent) {
		DoorInteractionComponent->OpenTheDoor(20.0f);
	}
}
