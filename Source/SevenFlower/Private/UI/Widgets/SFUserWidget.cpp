// Copyright QueueBitGames


#include "UI/Widgets/SFUserWidget.h"

void USFUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
