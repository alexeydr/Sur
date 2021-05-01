// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Components/InventoryComponent.h"
#include "StorageInventoryComponent.generated.h"

/**
 * 
 */

UCLASS()
class SUR_API UStorageInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:

	virtual void CreateWidgetInventory() override;
	
};
