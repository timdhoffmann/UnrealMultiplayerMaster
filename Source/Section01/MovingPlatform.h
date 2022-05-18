// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class SECTION01_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

#pragma region Variables

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MoveSpeed = 50.0f;

	float MaxDistanceTravelled = 0.0f;

	// Creates a gizmo in the editor.
	UPROPERTY(EditAnywhere, Category = Setup, Meta = (MakeEditWidget = true))
		FVector TargetLocation = FVector(0.0f, 0.0f, 0.0f);

	FVector GlobalStartLocation = FVector(0.0f);
	FVector GlobalTargetLocation = FVector(0.0f);
	FVector GlobalHeadingLocation = FVector(0.0f);


#pragma endregion


#pragma region Functions

public:
	AMovingPlatform();

protected:
	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;

#pragma endregion
};
