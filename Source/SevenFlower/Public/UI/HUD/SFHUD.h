// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetControllers/SFWidgetController.h"

#include "SFHUD.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAttributeMenuWidgetController;
class USFUserWidget;
/**
 * 
 */
UCLASS()
class SEVENFLOWER_API ASFHUD : public AHUD
{
	GENERATED_BODY()

public:

	// TODO сделать через фабрику ну или хотябы через одну функцию
	USFWidgetController* GetOrCreateWidgetController(const FWidgetControllerParams& WCParams);
	UOverlayWidgetController* GetOrCreateOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UAttributeMenuWidgetController* GetOrCreateAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
protected:
	

private:

	UPROPERTY()
	TObjectPtr<USFUserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<USFUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
