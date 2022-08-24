// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorInteractionComponent.h"
#include "InteractableDoor.h"
#include "Components/ActorComponent.h"
#include "ButtonToUnlockDoor.generated.h"

class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CGSPROJECT_API UButtonToUnlockDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UButtonToUnlockDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	ATriggerBox* triggerBox;

	UPROPERTY(EditAnywhere)
	AInteractableDoor* door = nullptr;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenTheDoor();
		
};
