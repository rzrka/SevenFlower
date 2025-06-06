// Copyright QueueBitGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SFCharacter.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class SEVENFLOWER_API ASFCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	ASFCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
