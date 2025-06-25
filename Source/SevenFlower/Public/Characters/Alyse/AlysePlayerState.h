// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Characters/SFPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "AlysePlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AAlysePlayerState : public ASFPlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAlysePlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}
	
protected:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
