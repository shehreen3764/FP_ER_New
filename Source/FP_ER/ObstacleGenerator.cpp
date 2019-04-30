// Fill out your copyright notice in the Description page of Project Settings.

#include "ObstacleGenerator.h"
#include "Obstacles/ObstacleBase.h"
#include "Obstacles/CoinBase.h"


// Sets default values
AObstacleGenerator::AObstacleGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AObstacleGenerator::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AObstacleGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacleGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacleGenerator::CreatePositiveObstacle(USceneComponent* Yourself, uint8 WhichIndex, const FVector &Location, const FRotator &Rotation)
{
	if (PositiveObstacles.Num() == 0) return;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		if (PositiveObstacles[WhichIndex] != nullptr)
		{
			ACoinBase* Obstacle = World->SpawnActor<ACoinBase>(PositiveObstacles[WhichIndex], Location, Rotation);
			if (Obstacle != nullptr)
			{
				Obstacle->AttachToComponent(Yourself, FAttachmentTransformRules::KeepWorldTransform);
			}
		}
		
		
	}
}

void AObstacleGenerator::CreateNegativeObstacle(USceneComponent* Yourself, uint8 WhichIndex, const FVector &Location, const FRotator &Rotation)
{
	if (NegativeObstacles.Num() == 0) return;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		if (NegativeObstacles[WhichIndex] != nullptr)
		{
			AObstacleBase* Obstacle = World->SpawnActor<AObstacleBase>(NegativeObstacles[WhichIndex], Location, Rotation);
			if (Obstacle != nullptr)
			{
				Obstacle->AttachToComponent(Yourself, FAttachmentTransformRules::KeepWorldTransform);
			}
		}
		
		
	}
}



