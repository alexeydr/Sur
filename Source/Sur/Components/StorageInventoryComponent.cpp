// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Components/StorageInventoryComponent.h"
#include "Sur/Library.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "CharacterInventoryComponent.h"
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Components/PanelWidget.h"
#include "Sur/Interfaces/UsableInterface.h"

void UStorageInventoryComponent::AddItem(APickUpActor* NewItem)
{
	Super::AddItem(NewItem);
	StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(this));
}

void UStorageInventoryComponent::OnSelectItem(IUsableInterface* SelectedItem)
{
	APickUpActor* Item = Cast<APickUpActor>(SelectedItem);
	UCharacterInventoryComponent* CharInv = Library::GetCharacterInventory(this);
   if (Item && CharInv)
    {
        if (CharInv->GetInventory().Contains(Item))
        {
			AddItem(Item);
			CharInv->RemoveItemFromInventory(Item);
        }
        else
        {
			RemoveItemFromInventory(Item);
			CharInv->AddItem(Item);
        }
		StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(Library::GetCharacterInventory(this)));
		StorageWidgetRef->AddToAdditionalWindow(StorageWidgetRef->FormBoxWithCells(this));
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


