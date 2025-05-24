// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SFUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API USFUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
