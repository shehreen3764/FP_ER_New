// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FP_ERGameMode.generated.h"

UCLASS(minimalapi)
class AFP_ERGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFP_ERGameMode();

	virtual void BeginPlay() override;//this creates error in tutorial. so he deleted. but without this doesn't build

};



