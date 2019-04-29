// Fill out your copyright notice in the Description page of Project Settings.

#include "RotatorComponent.h"
//#include "FP_ER.h"


// Sets default values for this component's properties
URotatorComponent::URotatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatorComponent::BeginPlay()
{
	Super::BeginPlay();
	uint8 Random = FMath::RandHelper(2);
	switch (Random)
	{
	case 0:
		bRotationDirection = true;
		break;
	case 1:
		bRotationDirection = false;
		break;

	}

	// ...
	
}


// Called every frame
void URotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!bCanRotate)
		return;
	StartRotating(DeltaTime, bRotationDirection);
	// ...
}

void URotatorComponent::StartRotating(float DeltaTime, bool Direction)
{
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	
	if (Direction)
	{
		CurrentRotation.Add(DeltaTime*RotationSpeedPitch, DeltaTime*RotationSpeedYaw, DeltaTime*RotationSpeedRoll);
		
	}

	else
	{
		CurrentRotation.Add(DeltaTime*-RotationSpeedPitch, DeltaTime*-RotationSpeedYaw, DeltaTime*-RotationSpeedRoll);
		
	}
	GetOwner()->SetActorRotation(CurrentRotation);
}

