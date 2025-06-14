// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "SFHUD.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class USFUserWidget;
/**
 * 
 */
UCLASS()
class SEVENFLOWER_API ASFHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<USFUserWidget> OverlayWidget;


	UOverlayWidgetController* GetOrCreateOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
protected:
	

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<USFUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
