// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Components/CharacterInventoryComponent.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Sur/UI/ItemViewWindow.h"
#include "Components/PanelWidget.h"

void UCharacterInventoryComponent::CreateWidgetInventory()
{
	Super::CreateWidgetInventory();
	if (StorageWidgetRef)
	{
		StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(this));
	}

}

void UCharacterInventoryComponent::AddItem(APickUpActor* NewItem)
{
	Super::AddItem(NewItem);
	if (StorageWidgetRef)
		StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(this));
}

void UCharacterInventoryComponent::RemoveItemFromInventory(APickUpActor* NewItem)
{
	Super::RemoveItemFromInventory(NewItem);
	if (StorageWidgetRef)
		StorageWidgetRef->AddToMainWindow(StorageWidgetRef->FormBoxWithCells(this));
}

void UCharacterInventoryComponent::OnSelectItem(IUsableInterface* SelectedItem)
{
	if (StorageWidgetRef && ViewPanelWidgetClass)
	{
		UItemViewWindow* ViewWindow = CreateWidget<UItemViewWindow>(GetWorld(), ViewPanelWidgetClass);
		ViewWindow->InitializeWidget(SelectedItem);
		if (ViewWindow)
		{
			StorageWidgetRef->AddToAdditionalWindow(ViewWindow);
		}
	}
}
