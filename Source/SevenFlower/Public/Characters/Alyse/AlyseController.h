// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AlyseController.generated.h"


struct FInputActionValue;
/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AAlyseController : public APlayerController
{
	GENERATED_BODY()
public:
	AAlyseController();

	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<class UInputMappingContext> AlyseContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<class UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<class UInputAction> LookAction;

	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
};
