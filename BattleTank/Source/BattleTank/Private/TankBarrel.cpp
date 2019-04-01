// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTank.h"

void UTankBarrel::Elevate(float RaletiveSpeed)
{
	RaletiveSpeed = FMath::Clamp<float>(RaletiveSpeed,-1,1);
	auto ElevationChange = RaletiveSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevationDegree,MaxElevationDegree);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}



