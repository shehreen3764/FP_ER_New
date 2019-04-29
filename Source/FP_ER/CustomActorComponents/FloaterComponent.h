// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FP_ERGameMode.h"
#include "Components/ActorComponent.h"
#include "FloaterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FP_ER_API UFloaterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFloaterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Custom Niall")
	uint32 bCanFloat : 1;

	UPROPERTY(VisibleAnywhere, Category = "Custom Niall")
		float RunningTime = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Custom Niall")
		float FloatingRate = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Custom Niall")
		float HeightPeek = 20.0f;

	void Float(float DeltaTime);


	
};
