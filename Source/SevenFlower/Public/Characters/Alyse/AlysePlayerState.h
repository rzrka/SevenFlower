// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "Characters/SFPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "AlysePlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class SEVENFLOWER_API AAlysePlayerState : public ASFPlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAlysePlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}

	FORCEINLINE int32 GetPlayerLevel() const {return Level; }
protected:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

private:
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_Level)
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
