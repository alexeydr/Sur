// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Components/InventoryComponent.h"
#include "StorageInventoryComponent.generated.h"

/**
 * 
 */
class APickUpActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAddToStorage, APickUpActor*, InActor);

UCLASS()
class SUR_API UStorageInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:

	FOnItemAddToStorage OnItemAddToStorage;

	virtual	void OnSelectItem(IUsableInterface* SelectedItem) override;

	virtual void CreateWidgetInventory() override;

};
