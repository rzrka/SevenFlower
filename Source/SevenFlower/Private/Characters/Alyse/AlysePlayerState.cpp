// Copyright QueueBitGames


#include "Characters/Alyse/AlysePlayerState.h"

#include "Characters/AbilitySystem/SFAbilitySystemComponent.h"
#include "Characters/AbilitySystem/SFAttributeSet.h"


AAlysePlayerState::AAlysePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USFAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AAlysePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

