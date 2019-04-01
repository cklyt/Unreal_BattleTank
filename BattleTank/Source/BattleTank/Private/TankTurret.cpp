// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"


void UTankTurret::Rotate(float RaletiveSpeed)
{
	RaletiveSpeed = FMath::Clamp<float>(RaletiveSpeed, -1, 1);
	auto RotationChange = RaletiveSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}
