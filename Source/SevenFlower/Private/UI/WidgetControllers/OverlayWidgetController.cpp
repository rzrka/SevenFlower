// Copyright QueueBitGames


#include "UI/WidgetControllers/OverlayWidgetController.h"

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
		).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetMaxHealthAttribute()
		).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetManaAttribute()
		).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SFAttributeSet->GetMaxManaAttribute()
		).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Health) const
{
	OnHealthChanged.Broadcast(Health.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& MaxHealth) const
{
	OnMaxHealthChanged.Broadcast(MaxHealth.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Mana) const
{
	OnManaChanged.Broadcast(Mana.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& MaxMana) const
{
	OnMaxManaChanged.Broadcast(MaxMana.NewValue);
}
