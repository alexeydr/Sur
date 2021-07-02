// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Interaction Actors/BaseInteractionActor.h"
#include "BaseStorageActor.generated.h"

/**
 * 
 */

class UStorageInventoryComponent;

UCLASS()
class SUR_API ABaseStorageActor : public ABaseInteractionActor
{
	GENERATED_BODY()

public:

	ABaseStorageActor();
					
	UPROPERTY(EditDefaultsOnly)
	UStorageInventoryComponent* InventoryComp;

	//IInteractionInterface interface

	virtual void OnInteraction() override;

	//End of IInteractionInterface interface
	
};
