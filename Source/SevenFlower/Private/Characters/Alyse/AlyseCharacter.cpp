// Copyright QueueBitGames


#include "Characters/Alyse/AlyseCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/AbilitySystem/SFAbilitySystemComponent.h"
#include "Characters/Alyse/AlyseController.h"
#include "Characters/Alyse/AlysePlayerState.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UI/HUD/SFHUD.h"

AAlyseCharacter::AAlyseCharacter()
{

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
		// SpringArm->SetWorldRotation(FRotator(-35.f, 0.f, 0.f));
		// SpringArm->SocketOffset = FVector(0, 0.f, 0.f);
		
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("View Camera"));
	ViewCamera->SetupAttachment(SpringArm);

	GetCharacterMovement()->SetJumpAllowed(true);
	
}

void AAlyseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAlyseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	// Init ability actor info for the Server
	InitAbilityActorInfo();
}	

void AAlyseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAlyseCharacter::InitAbilityActorInfo()
{
	AAlysePlayerState* AlysePlayerState = GetPlayerState<AAlysePlayerState>();
	check(AlysePlayerState);
	AlysePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AlysePlayerState, this);
	
	AbilitySystemComponent = AlysePlayerState->GetAbilitySystemComponent();
	Cast<USFAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	AttributeSet = AlysePlayerState->GetAttributeSet();

	if (AAlyseController* AlyseController = Cast<AAlyseController>(GetController()))
	{
		if (ASFHUD* SFHUD = Cast<ASFHUD>(AlyseController->GetHUD()))
		{
			SFHUD->InitOverlay(AlyseController, AlysePlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
 