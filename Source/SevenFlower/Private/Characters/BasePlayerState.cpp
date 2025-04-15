// Copyright QueueBitGames


#include "Characters/BasePlayerState.h"

#include "Characters/AbilitySystem/BaseAbilitySystemComponent.h"
#include "Characters/AbilitySystem/BaseAttributeSet.h"


ABasePlayerState::ABasePlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttibuteSet");
}

UAbilitySystemComponent* ABasePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
