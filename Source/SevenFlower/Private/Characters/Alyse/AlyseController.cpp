// Copyright QueueBitGames

#include "Characters/Alyse/AlyseController.h"
#include "Characters/Alyse/AlyseCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAlyseController::AAlyseController()
{
	bReplicates = true;
}

void AAlyseController::BeginPlay()
{
	Super::BeginPlay();
	check(AlyseContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AlyseContext, 0);
}

void AAlyseController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAlyseController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAlyseController::Look);
	EnhancedInputComponent->BindAction(WalkAction, ETriggerEvent::Triggered, this, &AAlyseController::Walk);
	EnhancedInputComponent->BindAction(WalkAction, ETriggerEvent::Completed, this, &AAlyseController::Walk);
	EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &AAlyseController::Crouch);
	EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AAlyseController::Crouch);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AAlyseController::Jump);
}

void AAlyseController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAlyseController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisValue = InputActionValue.Get<FVector2D>();
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(LookAxisValue.X);
		ControlledPawn->AddControllerPitchInput(LookAxisValue.Y);
	}
}

void AAlyseController::Walk(const FInputActionValue& InputActionValue)
{

	const bool bIsPressed = InputActionValue.Get<bool>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		if (AAlyseCharacter* ControlledCharacter = Cast<AAlyseCharacter>(ControlledPawn))
		{
			if (UCharacterMovementComponent* Movement = ControlledCharacter->GetCharacterMovement())
			{
				Movement->MaxWalkSpeed = bIsPressed ? ControlledCharacter->WalkSpeed : ControlledCharacter->RunSpeed;
			}
		}
	}
}

void AAlyseController::Crouch(const FInputActionValue& InputActionValue)
{
	const bool bIsPressed = InputActionValue.Get<bool>();
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		if (AAlyseCharacter* ControlledCharacter = Cast<AAlyseCharacter>(ControlledPawn))
		{
			if (bIsPressed)
			{
				ControlledCharacter->Crouch();
				ControlledCharacter->isCrouching = true;
			}
			else
			{
				ControlledCharacter->UnCrouch();
				ControlledCharacter->isCrouching = false;
			}
		}
	}
}

void AAlyseController::Jump(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		if (AAlyseCharacter* ControlledCharacter = Cast<AAlyseCharacter>(ControlledPawn))
		{
			ControlledCharacter->Jump();
		}
	}
}
