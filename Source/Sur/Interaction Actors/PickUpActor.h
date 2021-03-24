// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Interaction Actors/BaseInteractionActor.h"
#include "PickUpActor.generated.h"

/**
 * 
 */
UCLASS()
class SUR_API APickUpActor : public ABaseInteractionActor
{
	GENERATED_BODY()


public:
	//IInteractionInterface interface

	virtual float GetInteractionTime() override { return InteractionTime; }

	virtual AActor* GetOwningActor() override { return this; }

	virtual void OnBecameActive() override {};

	virtual void OnStoppedActive() override {};

	//End of IInteractionInterface interface
	
};
