// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"
//Forward Deceleration

class AProjectile;
class UTankBarrel;
class UTankTurret;

//Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	ReLoading,
	Aiming,
	OutOfAmmo,
	Locked
};

//Hold barrel properties and elevate methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:		
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
		void Fire();
	UFUNCTION(BlueprintCallable, Category = "SetUp")
		void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
		int GetRoundsLeft() const;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000.;
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringState = EFiringStatus::ReLoading;
private:
	//functions
	UTankAimingComponent();
	void MoveBarrelTowwards(FVector AimDirection);
	bool IsBarrelMoving();
	//pointers
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;	

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBP;
	
	// Sets default values for this component's properties
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
	FVector AimDirection = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int RoundsLeft = 5;
};
