// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// Might need to ensure running this on the server only!
	SetReplicates(true);
	SetReplicateMovement(true);

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	MaxDistanceTravelled = FVector::Dist(GlobalStartLocation, GlobalTargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!HasAuthority())
	{
		return;
	}

	FVector Location = GetActorLocation();
	float DistanceTravelled = FVector::Dist(Location, GlobalStartLocation);
	
	float Tolerance = 1.0f;
	if (DistanceTravelled >= MaxDistanceTravelled)
	{
		FVector TempLocation = GlobalTargetLocation;
		GlobalTargetLocation = GlobalStartLocation;
		GlobalStartLocation = TempLocation;
	}

	FVector TargetDirection = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
	Location += TargetDirection * MoveSpeed * DeltaTime;

	// Server code from here.

	SetActorLocation(Location);
}