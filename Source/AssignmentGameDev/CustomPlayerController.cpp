// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "PlayerCharacter.h"
#include "Blueprint/UserWidget.h" 

void ACustomPlayerController::BeginPlay() {
	Super::BeginPlay();
	Character = Cast<ACharacter>(GetPawn()); // Downcasting a pawn to the character
	MyCharacter = Cast<APlayerCharacter>(Character); // Downcasting a character to the Custom character
	HPCount = CreateWidget(this, HPHUDClass); // Creates a widget 


	if (HPCount != nullptr) {
		HPCount->AddToViewport(); // Adds a widget to the viewport
	}


}


void ACustomPlayerController::SetupInputComponent() { // Binds keys to the functions. Functions will be calling methods of the PlayerCharacter class
	Super::SetupInputComponent();
	InputComponent->BindAxis("Move Forwards", this, &ACustomPlayerController::CallForwards);
	InputComponent->BindAxis("Look up", this, &ACustomPlayerController::CallPitch);
	InputComponent->BindAxis("Strafe", this, &ACustomPlayerController::CallStrafe);
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::CallTurn);
    InputComponent->BindAction("Fire", IE_Pressed, this, &ACustomPlayerController::CallFire);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACustomPlayerController::CallJump);
	InputComponent->BindAction("Throw", IE_Pressed, this, &ACustomPlayerController::CallThrow);
}


void ACustomPlayerController::CallForwards(float Value)
{
	MyCharacter->MovementForward(Value);
}
void ACustomPlayerController::CallTurn(float Value)
{
	MyCharacter->Turn(Value);
}
void ACustomPlayerController::CallPitch(float Value)
{
	MyCharacter->PitchRot(Value);
}
void ACustomPlayerController::CallStrafe(float Value)
{
	MyCharacter->StrafeMov(Value);
}
void ACustomPlayerController::CallFire()
{
	MyCharacter->OnBeginFire();
}

void ACustomPlayerController::CallJump()
{
	MyCharacter->Jump1();
}

void ACustomPlayerController::CallThrow()
{
	MyCharacter->Throw();
}



int ACustomPlayerController::GetHP() // Gets current HP of the PlayerCharacter
{
	return MyCharacter->GetHP();
}


