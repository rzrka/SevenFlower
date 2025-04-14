// Copyright QueueBitGames


#include "Characters/Enemies/EnemyCharacter.h"

#include "Characters/AbilitySystem/BaseAbilitySystemComponent.h"
#include "Characters/AbilitySystem/BaseAttributeSet.h"
#include "SevenFlower/SevenFlower.h"

AEnemyCharacter::AEnemyCharacter()
{
	// Highlight
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttibuteSet");
}

void AEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void AEnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
