// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Characters/SFCharacter.h"
#include "Interaction/lightingInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AEnemyCharacter : public ASFCharacter, public IlightingInterface
{
	GENERATED_BODY()
public:
	AEnemyCharacter();
	
	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */
protected:
	virtual void BeginPlay() override;
};
