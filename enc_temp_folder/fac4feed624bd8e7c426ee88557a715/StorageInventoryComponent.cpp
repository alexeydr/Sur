// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Components/StorageInventoryComponent.h"
#include "Sur/Library.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "CharacterInventoryComponent.h"
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Components/PanelWidget.h"
#include "Sur/Interfaces/UsableInterface.h"

void UStorageInventoryComponent::RemoveItemFromInventory(APickUpActor* Item)
{
	Super::RemoveItemFromInventory(Item);
	if (StorageWidgetRef)
		StorageWidgetRef->AddToAdditionalWindow(StorageWidgetRef->FormBoxWithCells(this));
}

void UStorageInventoryComponent::AddItem(APickUpActor* NewItem)
{
	Super::AddItem(NewItem);
	if (StorageWidgetRef)
		StorageWidgetRef->AddToAdditionalWindow(StorageWidgetRef->FormBoxWithCells(this));
}

void UStorageInventoryComponent::OnSelectItem(IUsableInterface* SelectedItem)
{	
   if (APickUpActor* Item = Cast<APickUpActor>(SelectedItem))
    {
		Library::GetCharacterInventory(this)->AddItem(Item);
		RemoveItemFromInventory(Item);
    }
   
}

void UStorageInventoryComponent::CreateWidgetInventory()
{
	Super::CreateWidgetInventory();
	if (StorageWidgetRef)
	{
		StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(Library::GetCharacterInventory(this)));
		StorageWidgetRef->AddToAdditionalWindow(StorageWidgetRef->FormBoxWithCells(this));
	}
}


