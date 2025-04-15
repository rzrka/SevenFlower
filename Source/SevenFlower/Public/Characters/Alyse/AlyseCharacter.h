// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "AlyseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AAlyseCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AAlyseCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool isCrouching = false;
	
	const float WalkSpeed = 300.f;
	const float RunSpeed = 600.f;

private:
	void InitAbilityActorInfo();
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> ViewCamera;
};
