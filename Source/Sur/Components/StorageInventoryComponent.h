// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Components/InventoryComponent.h"
#include "StorageInventoryComponent.generated.h"

/**
 * 
 */
class APickUpActor;


UCLASS()
class SUR_API UStorageInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:

	virtual void AddItem(APickUpActor* NewItem) override;

	virtual	void OnSelectItem(IUsableInterface* SelectedItem) override;

	virtual void CreateWidgetInventory() override;

};
