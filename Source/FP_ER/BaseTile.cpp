// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTile.h"
#include "FP_ER.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "TileGenerator.h"
#include "ObstacleGenerator.h"
#include "FP_ERCharacter.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ABaseTile::ABaseTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (TActorIterator<ATileGenerator> ActorItr(World); ActorItr; ++ActorItr)
		{
			TileManager = *ActorItr;
		}
		for (TActorIterator<AObstacleGenerator> ActorItr2(World); ActorItr2; ++ActorItr2)
		{
			ObstacleManager = *ActorItr2;
		}
	}
}

void ABaseTile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	InitialiseArrows();
	InitialiseTriggers();
	if (Triggers.Num() == 0)return;
	Triggers[0]->OnComponentBeginOverlap.AddDynamic(this, &ABaseTile::OnTriggerEnter);
}

// Called when the game starts or when spawned
void ABaseTile::BeginPlay()
{
	Super::BeginPlay();
	
	uint8 Result = FMath::RandHelper(2);
	switch (Result)
	{
	case 0:
		CreateCoins();
		break;
	case 1:
		CreateObstacles();
		break;
	default:
		CreateCoins();
		break;
	}
}

// Called every frame
void ABaseTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseTile::InitialiseTriggers()
{
	TArray<UActorComponent*> Components = GetComponentsByClass(UBoxComponent::StaticClass());
	if (Components.Num() == 0)
	{
		return;
	}
	for (size_t i = 0; i < Components.Num(); i++)
	{
		UBoxComponent* ThisTrigger = Cast<UBoxComponent>(Components[i]);
		if (ThisTrigger != nullptr)
		{
			//0 spawner, 1 coin box
			ThisTrigger->SetGenerateOverlapEvents(true);
			Triggers.Add(ThisTrigger);
		}

	}
}

void ABaseTile::InitialiseArrows()
{
	TArray<UActorComponent*> Components = GetComponentsByClass(UArrowComponent::StaticClass());
	if (Components.Num() == 0)
	{
		return;
	}
	for (size_t i = 0; i < Components.Num(); i++)
	{
		UArrowComponent* ThisArrow = Cast<UArrowComponent>(Components[i]);
		if (ThisArrow != nullptr)
		{
			//0 spawner, 1 coin box
			//ThisArrow->SetGenerateOverlapEvents = true;
			Arrows.Add(ThisArrow);
		}

	}
}

void ABaseTile::CreateObstacles()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		uint8 NumberOfObstaclesToSpawn = FMath::RandRange(1,ObstacleManager->MaxNumberOfObstacles);
		
		for (size_t i = 0; i < NumberOfObstaclesToSpawn; i++)
		{
			const FVector Location = Arrows[1+i]->GetComponentLocation();
			const FRotator Rotation = Arrows[1+i]->GetComponentRotation();
			uint8 RandomObstacle = FMath::RandRange(0, ObstacleManager->NegativeObstacles.Num()-1);
			ObstacleManager->CreateNegativeObstacle(GetRootComponent(), RandomObstacle, Location, Rotation);
		}
	}
}

void ABaseTile::CreateCoins()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		uint8 NumberOfCoinsToSpawn = FMath::RandRange(5, 15);

		for (size_t i = 0; i < NumberOfCoinsToSpawn; i++)
		{
			const FVector SpawnOrigin = Triggers[1]->Bounds.Origin;
			const FVector SpawnExtent = Triggers[1]->Bounds.BoxExtent;
			
			const FVector Location = UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
			const FRotator Rotation = GetActorRotation();
			ObstacleManager->CreatePositiveObstacle(this->GetRootComponent(), 0, Location, Rotation);
		}
	}

}

FTransform ABaseTile::SetObstacleSpawns()
{
	uint8 ObstaclesSpawnIndex = FMath::RandHelper(3);

	if (Arrows[ObstaclesSpawnIndex + 1] != nullptr)
	{
		return Arrows[ObstaclesSpawnIndex + 1]->GetComponentTransform();
	}
	else
	{
		return FTransform();
	}
}

FTransform ABaseTile::GetNextSpawnTransform()
{
	if (Arrows[0] != nullptr)
	{
		return Arrows[0]->GetComponentTransform();
	}
	else
	{
		return FTransform();
	}
}

void ABaseTile::OnTriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check against player
	AFP_ERCharacter* MyCharacter = Cast<AFP_ERCharacter>(OtherActor);
	if (MyCharacter != nullptr)
	{
		//Get a ref to world
		UWorld* const World = GetWorld();		
		if (World != nullptr)
		{
			if (TileManager != nullptr)
			{
				//make some tiles
				TileManager->CreateTile();
				//Delete After 2 seconds
				World->GetTimerManager().SetTimer(DelayForDestroyMe, this, &ABaseTile::DestroyMe, 2.0f);
			}
		}
	}
}

void ABaseTile::DestroyMe()
{
	Destroy();
}
