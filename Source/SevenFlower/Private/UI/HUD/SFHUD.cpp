// Copyright QueueBitGames


#include "UI/HUD/SFHUD.h"

#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "UI/WidgetControllers/AttributeMenuWidgetController.h"
#include "UI/Widgets/SFUserWidget.h"


template<typename T>
T* ASFHUD::GetOrCreateWidgetController(const FWidgetControllerParams& WCParams, TObjectPtr<T>& WidgetController, TSubclassOf<T> WidgetControllerClass)
{
	if (WidgetController) return WidgetController;

	WidgetController = NewObject<T>(this, WidgetControllerClass);
	WidgetController->SetWidgetControllerParams(WCParams);
	WidgetController->BindCallbacksToDependencies();

	return WidgetController;
}

UOverlayWidgetController* ASFHUD::GetOrCreateOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	return GetOrCreateWidgetController(WCParams, OverlayWidgetController, OverlayWidgetControllerClass);
}

UAttributeMenuWidgetController* ASFHUD::GetOrCreateAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	return GetOrCreateWidgetController(WCParams, AttributeMenuWidgetController, AttributeMenuWidgetControllerClass);
}

void ASFHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_SFHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_SFHUD"));
	
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<USFUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOrCreateOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}
