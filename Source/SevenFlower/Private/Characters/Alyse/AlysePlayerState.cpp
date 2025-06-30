// Copyright QueueBitGames


#include "Characters/Alyse/AlysePlayerState.h"

#include "Characters/AbilitySystem/SFAbilitySystemComponent.h"
#include "Characters/AbilitySystem/SFAttributeSet.h"
#include "Net/UnrealNetwork.h"


AAlysePlayerState::AAlysePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<USFAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

void AAlysePlayerState:: GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAlysePlayerState, Level);
}

UAbilitySystemComponent* AAlysePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAlysePlayerState::OnRep_Level(int32 OldLevel)
{
}

