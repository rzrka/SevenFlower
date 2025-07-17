// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/SFWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"
class UAttributeInfo;
struct FSFAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FSFAttributeInfo&, Info);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SEVENFLOWER_API UAttributeMenuWidgetController : public USFWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FAttributeInfoSignature AttributeInfoDelegate;

private:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;
};
