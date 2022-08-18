// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
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
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
		if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn)) {	 //once its overlapped //why is it crashing here
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, TEXT("overlapped!"));
			}
			if (CurrentRotationTime < TimeToRotate) {  //this tells it to start rotating
				if (GEngine) {
					GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, TEXT("Began Rotation!"));
				}
				while (!HasCaluclatedVector) {
					//const float DotProduct =  FVector::DotProduct(PlayerPawn->GetActorForwardVector(), GetOwner()->GetActorLocation());
					//float DegreesOutput = FMath::RadiansToDegrees(DotProduct);
					//FString TheFloatStr = FString::SanitizeFloat(DegreesOutput); //just for printing dot prodcut
					//if (GEngine) {
					//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, *TheFloatStr);
					//}
					FVector playerForward = PlayerPawn->GetActorForwardVector();
					FVector doorPos = GetOwner()->GetActorLocation();
					FVector toDoor = (PlayerPawn->GetActorLocation() - doorPos).GetSafeNormal(); //this doestn resolve it 
					float angleToDoor = FVector::DotProduct(playerForward, toDoor);

					if (angleToDoor > 0.0f) {
						if (GEngine) {
							GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Yellow, TEXT("Same Direction"));
						}
						//same direction
						FinalRotation += FRotator(0.0f, 50.0f, 0.0f);
						HasCaluclatedVector = true;
					}
					else if (angleToDoor < 0.0f) {
						if (GEngine) {
							GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OppositeDirection"));
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

