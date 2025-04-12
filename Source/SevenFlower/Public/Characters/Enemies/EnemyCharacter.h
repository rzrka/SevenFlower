// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Interaction/lightingInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AEnemyCharacter : public ABaseCharacter, public IlightingInterface
{
	GENERATED_BODY()
public:
	AEnemyCharacter();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
};
