// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Components/InventoryComponent.h"
#include "CharacterInventoryComponent.generated.h"

class UItemViewWindow;

/**
 * 
 */
UCLASS()
class SUR_API UCharacterInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:

	virtual void RemoveItemFromInventory(APickUpActor* Item);

	virtual void AddItem(APickUpActor* NewItem);

	virtual	void OnSelectItem(IUsableInterface* SelectedItem);

	virtual void CreateWidgetInventory() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UItemViewWindow> ViewPanelWidgetClass;

};
