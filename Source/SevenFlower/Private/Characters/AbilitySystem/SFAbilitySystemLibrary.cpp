// Copyright QueueBitGames


#include "Characters/AbilitySystem/SFAbilitySystemLibrary.h"

#include "Characters/SFPlayerState.h"
#include "Characters/Alyse/AlysePlayerState.h"
#include "UI/WidgetControllers/SFWidgetController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/SFHUD.h"

UOverlayWidgetController* USFAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ASFHUD* SFHUD = Cast<ASFHUD>(PC->GetHUD()))
		{
			AAlysePlayerState* PS = PC->GetPlayerState<AAlysePlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return SFHUD->GetOrCreateOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* USFAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ASFHUD* SFHUD = Cast<ASFHUD>(PC->GetHUD()))
		{
			AAlysePlayerState* PS = PC->GetPlayerState<AAlysePlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return SFHUD->GetOrCreateAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
