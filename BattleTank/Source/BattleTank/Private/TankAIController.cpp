// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	if (!PlayerTank)
	{
		PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
	if (!ControlledTank)
	{
		ControlledTank= Cast<ATank>(GetPawn());
	}
	if (ControlledTank&&PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
	
}

