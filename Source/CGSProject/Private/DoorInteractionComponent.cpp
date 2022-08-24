// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "InteractableDoor.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UDoorInteractionComponent::UDoorInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	StartRotation = GetOwner()->GetActorRotation();
	FinalRotation = GetOwner()->GetActorRotation();
	
	CurrentRotationTime = 0;
	CurrentReturnTime = 0;
	HasCaluclatedVector = false;

	// ...
	
}




// Called every frame
void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (needbutton) {
		if (buttonPressed) {
			OpenTheDoor(DeltaTime);
		}
	}
	if (!needbutton) {
		OpenTheDoor(DeltaTime);
	}
	
	
}

void UDoorInteractionComponent::OpenTheDoor(float DeltaTime) {
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn)) {	 //once its overlapped //why is it crashing here
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, TEXT("overlapped!"));
		}
		if (CurrentRotationTime < TimeToRotate) {  //this tells it to start rotating
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, TEXT("Began Rotation!"));
			}
			if (!HasCaluclatedVector) {
				//const float DotProduct =  FVector::DotProduct(GetOwner(), (GetOwner()->GetActorLocation())); //fvetcor door to player //this is player pawn Plyer pwn get actor location - get woner get actor location
				//float DegreesOutput = FMath::RadiansToDegrees(DotProduct); has to be a direction
				//FString TheFloatStr = FString::SanitizeFloat(DegreesOutput); //just for printing dot prodcut
				//if (GEngine) {
				//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, *TheFloatStr);
				//}
				FVector doorForward = GetOwner()->GetActorLocation();
				FVector doorPos = GetOwner()->GetActorLocation();
				FVector toPlayer = (PlayerPawn->GetActorLocation() - doorPos).GetSafeNormal();
				float angleToDoor = FVector::DotProduct(doorForward, toPlayer);

				if (angleToDoor > 0.0f) {
					if (GEngine) {
						GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Yellow, TEXT("Postive"));
					}
					//same direction
					FinalRotation += FRotator(0.0f, 50.0f, 0.0f);
					HasCaluclatedVector = true;
				}
				else {
					if (GEngine) {
						GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Negative"));
					}
					//opposite direction
					FinalRotation += FRotator(0.0f, -50.0f, 0.0f);
					HasCaluclatedVector = true;
				}
			}

			CurrentRotationTime += DeltaTime;
			const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
			const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
			const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);
			GetOwner()->SetActorRotation(CurrentRotation);
		}
	}
}

void UDoorInteractionComponent::PressTheButton()
{
	buttonPressed = true;
}

bool UDoorInteractionComponent::NeedButtonPressed()
{
	return needbutton;
}


