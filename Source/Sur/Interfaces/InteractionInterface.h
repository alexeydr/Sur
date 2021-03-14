// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, BlueprintType)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
	
};

class IInteractionInterface
{
	GENERATED_BODY()

public:

	virtual AActor* GetOwningActor() { return nullptr; }

	virtual void OnBecameActive() {}

	virtual void OnStoppedActive() {}

	virtual void OnInteraction() {}

	virtual void OnStopInteraction() {}

};