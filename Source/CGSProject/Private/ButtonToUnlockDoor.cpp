// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonToUnlockDoor.h"
#include "Engine/TriggerBox.h"

// Sets default values for this component's properties
UButtonToUnlockDoor::UButtonToUnlockDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UButtonToUnlockDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UButtonToUnlockDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn && triggerBox->IsOverlappingActor(PlayerPawn)) {
		// ...
		if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "You Overlapped the box!");
			}
		if (door != nullptr) {
			//door->buttonPressed = true;
		}
	}
}


