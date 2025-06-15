// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SFAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API USFAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void AbilityActorInfoSet();
	
protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
