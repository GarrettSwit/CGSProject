// Fill out your copyright notice in the Description page of Project Settings.


#include "WiggletheObject.h"

// Sets default values
AWiggletheObject::AWiggletheObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWiggletheObject::BeginPlay()
{
	Super::BeginPlay();
	PreviousRotation = GetOwner()->GetActorRotation();
	NewRotation = GetOwner()->GetActorRotation();
	
}

// Called every frame
void AWiggletheObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NewRotation += FRotator(0.0f, 1.0f, 0.0f);
	GetOwner()->SetActorRotation(NewRotation * DeltaTime); //add one degree every tick

}

