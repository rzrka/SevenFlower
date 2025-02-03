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
	// virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> ViewCamera;
};
