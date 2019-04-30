// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FP_ERGameMode.h"
#include "Engine.h"
#include "FP_ERHUD.h"
#include "FP_ERCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFP_ERGameMode::AFP_ERGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFP_ERHUD::StaticClass();
}

//called when the game starts or when spawned
//this creates error in tutorial. so he deleted. but without this doesn't build
void AFP_ERGameMode::BeginPlay()
{
	Super::BeginPlay();

}

