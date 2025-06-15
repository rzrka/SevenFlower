// Copyright QueueBitGames


#include "Characters/SFCharacter.h"


ASFCharacter::ASFCharacter()
{	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ASFCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void ASFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASFCharacter::InitAbilityActorInfo()
{
}
