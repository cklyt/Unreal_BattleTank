// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) return;
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto  AIRotationIntention = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	IntendIntendTurnRight(AIRotationIntention);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	RightTrack->SetTrottle(Throw);
	LeftTrack->SetTrottle(Throw);
}

void UTankMovementComponent::IntendIntendTurnRight(float Throw)
{
	RightTrack->SetTrottle(-Throw);
	LeftTrack->SetTrottle(Throw);
}