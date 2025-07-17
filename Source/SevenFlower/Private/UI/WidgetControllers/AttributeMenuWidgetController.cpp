// Copyright QueueBitGames


#include "UI/WidgetControllers/AttributeMenuWidgetController.h"

#include "Characters/AbilitySystem/SFAttributeSet.h"
#include "Characters/AbilitySystem/Data/AttributeInfo.h"
#include "SFGameplayTags.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	USFAttributeSet* AS = CastChecked<USFAttributeSet>(AttributeSet);

	check(AttributeInfo);

	FSFAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FSFGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{

}
