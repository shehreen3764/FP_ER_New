// Fill out your copyright notice in the Description page of Project Settings.
#include "CornerTiles.h"
#include "FP_ER.h"
#include "FP_ERCharacter.h"

// Sets default values
//ACornerTile::ACornerTile()
//{
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	UWorld* const World = GetWorld();
//	if (World != nullptr)
//	{
//		for (TActorIterator<ATileGenerator> ActorItr(World); ActorItr; ++ActorItr)
//		{
//			TileManager = *ActorItr;
//		}
//	}
//}
//
//void ACornerTile::PostInitializeComponents()
//{
//	//Super::PostInitializeComponents();
//	InitialiseArrows();
//	InitialiseTriggers();
//	if (Triggers.Num() == 0)return;
//	Triggers[0]->OnComponentBeginOverlap.AddDynamic(this, &ABaseTile::OnTriggerEnter);
//	//Triggers[2]->OnComponentHit.AddDynamic(this, &AFP_ERCharacter::Death);
//}
//
//// Called when the game starts or when spawned
//void ACornerTile::BeginPlay()
//{
//	Super::BeginPlay();
//
//	uint8 Result = FMath::RandHelper(2);
//	switch (Result)
//	{
//	case 0:
//		CreateCoins();
//		break;
//	case 1:
//		CreateObstacles();
//		break;
//	}
//}
//
//// Called every frame
//void ACornerTile::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}
//
//void ACornerTile::InitialiseTriggers()
//{
//	TArray<UActorComponent*> Components = GetComponentsByClass(UBoxComponent::StaticClass());
//	if (Components.Num() == 0)
//	{
//		return;
//	}
//	for (size_t i = 0; i < Components.Num(); i++)
//	{
//		UBoxComponent* ThisTrigger = Cast<UBoxComponent>(Components[i]);
//		if (ThisTrigger != nullptr)
//		{
//			//0 spawner, 1 coin box
//			ThisTrigger->SetGenerateOverlapEvents(true);
//			Triggers.Add(ThisTrigger);
//		}
//
//	}
//}
//
//void ACornerTile::InitialiseArrows()
//{
//	TArray<UActorComponent*> Components = GetComponentsByClass(UArrowComponent::StaticClass());
//	if (Components.Num() == 0)
//	{
//		return;
//	}
//	for (size_t i = 0; i < Components.Num(); i++)
//	{
//		UArrowComponent* ThisArrow = Cast<UArrowComponent>(Components[i]);
//		if (ThisArrow != nullptr)
//		{
//			//0 spawner, 1 coin box
//			//ThisArrow->SetGenerateOverlapEvents = true;
//			Arrows.Add(ThisArrow);
//		}
//
//	}
//}
//
//void ACornerTile::CreateObstacles()
//{
//
//}
//
//void ACornerTile::CreateCoins()
//{
//
//}
//
//FTransform ACornerTile::SetObstacleSpawns()
//{
//	uint8 ObstaclesSpawnIndex = FMath::RandHelper(3);
//
//	if (Arrows[ObstaclesSpawnIndex + 1] != nullptr)
//	{
//		return Arrows[ObstaclesSpawnIndex + 1]->GetComponentTransform();
//	}
//	else
//	{
//		return FTransform();
//	}
//}