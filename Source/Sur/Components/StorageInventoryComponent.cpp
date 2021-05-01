// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Components/StorageInventoryComponent.h"
#include "Sur/Library.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "CharacterInventoryComponent.h"
#include "Components/PanelWidget.h"

void UStorageInventoryComponent::CreateWidgetInventory()
{
	Super::CreateWidgetInventory();
	if (StorageWidgetRef)
	{
		StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(Library::GetCharacterInventory(this)));
		StorageWidgetRef->AddToAdditionalWindow(StorageWidgetRef->FormBoxWithCells(this));
	}
}

