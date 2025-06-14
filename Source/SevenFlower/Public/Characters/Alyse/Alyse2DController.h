// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Alyse2DController.generated.h"



struct FInputActionValue;


class IlightingInterface;
/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AAlyse2DController : public APlayerController
{
	GENERATED_BODY()

public:
	AAlyse2DController();
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<class UInputMappingContext> AlyseContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<class UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	TObjectPtr<IlightingInterface> LastActor;
	TObjectPtr<IlightingInterface> ThisActor;
};
