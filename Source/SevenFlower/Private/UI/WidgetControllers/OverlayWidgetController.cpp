// Copyright QueueBitGames


#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "Characters/AbilitySystem/SFAbilitySystemComponent.h"
#include "Characters/AbilitySystem/SFAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USFAttributeSet* SFAttributeSet = CastChecked<USFAttributeSet>(AttributeSet);
	

	OnHealthChanged.Broadcast(SFAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SFAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(SFAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(SFAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const USFAttributeSet* SFAttributeSet = CastChecked<USFAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetHealthAttribute()
		).AddLambda(
			[this](const FOnAttributeChangeData& Health)
			{
				OnHealthChanged.Broadcast(Health.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetMaxHealthAttribute()
		).AddLambda(
			[this](const FOnAttributeChangeData& MaxHealth)
			{
				OnMaxHealthChanged.Broadcast(MaxHealth.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetManaAttribute()
		).AddLambda(
			[this](const FOnAttributeChangeData& Mana)
			{
				OnManaChanged.Broadcast(Mana.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetMaxManaAttribute()
		).AddLambda(
			[this](const FOnAttributeChangeData& MaxMana)
			{
				OnMaxManaChanged.Broadcast(MaxMana.NewValue);
			}
		);

	Cast<USFAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				
				const FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowSignature.Broadcast(*Row);
				}
			}
		}
	);
}
