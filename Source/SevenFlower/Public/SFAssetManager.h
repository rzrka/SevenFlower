// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SFAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API USFAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static USFAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
