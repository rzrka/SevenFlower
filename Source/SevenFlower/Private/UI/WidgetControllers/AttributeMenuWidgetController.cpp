// Copyright QueueBitGames


#include "UI/WidgetControllers/AttributeMenuWidgetController.h"

#include "Characters/AbilitySystem/SFAttributeSet.h"
#include "Characters/AbilitySystem/Data/AttributeInfo.h"
#include "SFGameplayTags.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	USFAttributeSet* AS = CastChecked<USFAttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (auto& Pair : AS->TagsToAttributes)
	{
		FSFAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		FGameplayAttribute Attr = Pair.Value();
		Info.AttributeValue = Attr.GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}
	
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{

}
