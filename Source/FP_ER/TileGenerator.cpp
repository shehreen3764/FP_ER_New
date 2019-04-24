// Fill out your copyright notice in the Description page of Project Settings.

#include "TileGenerator.h"
#include "FP_ER.h"
#include "BaseTile.h"


// Sets default values
ATileGenerator::ATileGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NextSpawnPoint = FTransform();
}

void ATileGenerator::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CreateStartingTiles();
}

// Called when the game starts or when spawned
void ATileGenerator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATileGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATileGenerator::CreateStartingTiles()
{
	for (size_t i = 0; i < 9; i++)
	{
		CreateTile();
	}
}

void ATileGenerator::CreateTile()
{
	//if either array is empty STOP
	if (TileStraights.Num() == 0) return;
	if (TileCorners.Num() == 0) return;

	//if we have "x" straights in a row, switch it with a corner
	if (CurrentStraightsCounter > MaxStraightsCounter)
	{
		AddCornerTile();
		return;
	}
	else
	{
		AddFloorTile();
		return;
	}
}

void ATileGenerator::AddFloorTile()
{
	//obtain a random index for which tile to spawn
	uint8 RandomStraightTile = FMath::RandHelper(TileStraights.Num());

	//check if valid
	if (TileStraights[RandomStraightTile] != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			//get pre-requisites for spawning
			const FVector SpawnLocation = NextSpawnPoint.GetLocation();
			const FRotator SpawnRotation = NextSpawnPoint.GetRotation().Rotator();

			//Spawn Tile
			ABaseTile* Tile = World->SpawnActor<ABaseTile>(TileStraights[RandomStraightTile], SpawnLocation, SpawnRotation);
			//check if success
			if (Tile != nullptr)
			{
				//increment the tile counter
				CurrentStraightsCounter++;
				//setup next spawn positions
				NextSpawnPoint = Tile->GetNextSpawnTransform();
			}
		}
		
	}
}

void ATileGenerator::AddCornerTile()
{
	//obtain a random index for which tile to spawn
	uint8 RandomCornerTile = FMath::RandHelper(TileCorners.Num());

	//check if valid
	if (TileCorners[RandomCornerTile] != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			//get pre-requisites for spawning
			const FVector SpawnLocation = NextSpawnPoint.GetLocation();
			const FRotator SpawnRotation = NextSpawnPoint.GetRotation().Rotator();

			//Spawn Tile
			ABaseTile* Tile = World->SpawnActor<ABaseTile>(TileCorners[RandomCornerTile], SpawnLocation, SpawnRotation);
			//check if success
			if (Tile != nullptr)
			{
				//increment the tile counter
				CurrentStraightsCounter = 0;
				//setup next spawn positions
				NextSpawnPoint = Tile->GetNextSpawnTransform();
			}
		}

	}
}