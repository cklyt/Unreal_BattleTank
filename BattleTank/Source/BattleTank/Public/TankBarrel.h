// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent),hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float RaletiveSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly)
	float MaxDegreePerSecond = 5;

	UPROPERTY(EditDefaultsOnly)
	float MaxElevationDegree = 40;
	UPROPERTY(EditDefaultsOnly)
	float MinElevationDegree = 0;


};
