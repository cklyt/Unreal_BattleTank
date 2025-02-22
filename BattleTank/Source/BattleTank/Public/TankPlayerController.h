// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATankPlayerController();
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingCompRef);
private:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const ;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation=0.333;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation=0.5;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.0;
};
