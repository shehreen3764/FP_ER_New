// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FP_ERGameMode.h"
#include "Components/ActorComponent.h"
#include "RotatorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FP_ER_API URotatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotatorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Rotation Speed
	UPROPERTY(EditAnywhere, Category = "Custom Niall")
		float RotationSpeedRoll = 0.0f;

	//Rotation Speed
	UPROPERTY(EditAnywhere, Category = "Custom Niall")
		float RotationSpeedPitch = 0.0f;

	//Rotation Speed
	UPROPERTY(EditAnywhere, Category = "Custom Niall")
		float RotationSpeedYaw = 0.0f;

	//Bool can Rotate 
	UPROPERTY(EditAnywhere, Category = "Custom Niall")
		uint32 bCanRotate : 1;

	//Rotation direction
	UPROPERTY(VisibleAnywhere, Category = "Custom Niall")
		uint32 bRotationDirection : 1;

	void StartRotating(float DeltaTime, bool Direction);
	
};
