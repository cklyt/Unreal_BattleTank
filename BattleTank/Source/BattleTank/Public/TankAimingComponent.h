// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"
//Forward Deceleration
class UTankBarrel;
class UTankTurret;

//Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	ReLoading,
	Aiming,
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

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Fire();
	UFUNCTION(BlueprintCallable, Category = "SetUp")
		void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 100000.;
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringState = EFiringStatus::Locked;
private:
	//functions
	UTankAimingComponent();
	void MoveBarrelTowwards(FVector AimDirection);

	//pointers
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		UClass* ProjectileBP;
	
	// Sets default values for this component's properties
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
};
