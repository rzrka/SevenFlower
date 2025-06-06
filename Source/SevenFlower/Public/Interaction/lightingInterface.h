// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "lightingInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UlightingInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SEVENFLOWER_API IlightingInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
