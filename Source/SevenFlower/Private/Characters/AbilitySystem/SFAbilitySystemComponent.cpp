// Copyright QueueBitGames


#include "Characters/AbilitySystem/SFAbilitySystemComponent.h"

#include "SFGameplayTags.h"

void USFAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &USFAbilitySystemComponent::EffectApplied);

	const FSFGameplayTags& GameplayTags = FSFGameplayTags::Get();
	// GameplayTags.Attributes_Secondary_Armor.ToString()
	
}

void USFAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                              const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
}
