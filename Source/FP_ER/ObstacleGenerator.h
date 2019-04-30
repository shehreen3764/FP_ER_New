// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleGenerator.generated.h"

UCLASS()
class FP_ER_API AObstacleGenerator : public AActor
{
	GENERATED_BODY()

	/**
	 * The functions of interest to initialization order for an Actor is roughly as follows:
	 * PostLoad/PostActorCreated - Do any setup of the actor required for construction. PostLoad for serialized actors, PostActorCreated for spawned.
	 * AActor::OnConstruction - The construction of the actor, this is where Blueprint actors have their components created and blueprint variables are initialized
	 * AActor::PreInitializeComponents - Called before InitializeComponent is called on the actor's components
	 * UActorComponent::InitializeComponent - Each component in the actor's components array gets an initialize call (if bWantsInitializeComponent is true for that component)
	 * AActor::PostInitializeComponents - Called after the actor's components have been initialized
	 * AActor::BeginPlay - Called when the level is started
	**/

	virtual void PostInitializeComponents() override;

	//protected:
		// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//public:	
		// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
public:	
	// Sets default values for this actor's properties
	AObstacleGenerator();

	void CreatePositiveObstacle(USceneComponent* Self, uint8 WhichIndex, const FVector& Location, const FRotator& Rotation);
	void CreateNegativeObstacle(USceneComponent* Self, uint8 WhichIndex, const FVector& Location, const FRotator& Rotation);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Niall")
		TArray<TSubclassOf<class AObstacleBase>> NegativeObstacles;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Niall")
		TArray<TSubclassOf<class ACoinBase>> PositiveObstacles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Niall")
	int32 MaxNumberOfObstacles = 2;
};
