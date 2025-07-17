// Copyright QueueBitGames


#include "SFAssetManager.h"

#include "SFGameplayTags.h"

USFAssetManager& USFAssetManager::Get()
{
	check(GEngine);
	
	USFAssetManager* SFAssetManager = Cast<USFAssetManager>(GEngine->AssetManager);
	return *SFAssetManager;
}

void USFAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FSFGameplayTags::InitializeNativeGameplayTags();
}
