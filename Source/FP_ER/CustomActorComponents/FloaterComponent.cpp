// Fill out your copyright notice in the Description page of Project Settings.

#include "FloaterComponent.h"


// Sets default values for this component's properties
UFloaterComponent::UFloaterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFloaterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFloaterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bCanFloat)
		return;
	Float(DeltaTime);
	// ...
}

void UFloaterComponent::Float(float DeltaTime)
{
	FVector NewLocation = GetOwner()->GetActorLocation();
	
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * HeightPeek;
	RunningTime += DeltaTime * FloatingRate;
	GetOwner()->SetActorLocation(NewLocation);

}

