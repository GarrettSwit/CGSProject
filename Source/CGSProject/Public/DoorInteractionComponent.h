// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Math/UnrealMathUtility.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorInteractionComponent.generated.h"


class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CGSPROJECT_API UDoorInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionComponent();

protected:
	// Called when the game starts

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	FRotator DesiredRotation;

	FRotator StartRotation;
	FRotator FinalRotation;


	UPROPERTY(EditAnywhere)
		float TimeToRotate = 0;
	float CurrentRotationTime = 0;

	UPROPERTY(EditAnywhere)
		ATriggerBox* TriggerBox;
	UPROPERTY(EditAnywhere)
	FRuntimeFloatCurve OpenCurve;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
