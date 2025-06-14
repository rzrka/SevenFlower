// Copyright QueueBitGames


#include "UI/WidgetControllers/SFWidgetController.h"

void USFWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void USFWidgetController::BroadcastInitialValues()
{
}

void USFWidgetController::BindCallbacksToDependencies()
{
}
