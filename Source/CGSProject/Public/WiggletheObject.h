// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WiggletheObject.generated.h"

UCLASS()
class CGSPROJECT_API AWiggletheObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWiggletheObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FRotator PreviousRotation;
	FRotator NewRotation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
