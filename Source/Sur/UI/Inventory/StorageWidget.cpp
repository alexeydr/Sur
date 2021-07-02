// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/Inventory/StorageWidget.h"
#include "Components/GridPanel.h"
#include "Components/SizeBox.h"
#include "Sur/Components/InventoryComponent.h"
#include "Sur/UI/BaseCellUserWidget.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "Sur/UI/ItemViewWindow.h"
#include "Sur/SurTypes.h"
#include "Components/GridSlot.h"

void UStorageWidget::AddToAdditionalWindow(UWidget* Content)
{
	AdditionalBox->ClearChildren();
	AdditionalBox->AddChild(Content);
}

void UStorageWidget::AddToMainWindow(UWidget* Content)
{
	MainBox->ClearChildren();
	MainBox->AddChild(Content);
}

UPanelWidget* UStorageWidget::FormBoxWithCells(UInventoryComponent* SourceComponent)
{
	UGridPanel* StorageGrid = NewObject<UGridPanel>();
	const auto& Inventory = SourceComponent->GetInventory();
	const auto& Capacity = SourceComponent->GetInventoryCapacity();
	int Iter = 0;
	for (int Column = 0; Column < Capacity.VerticalCapacity; Column++)
	{
		StorageGrid->SetColumnFill(Column, 1.f);
		for (int Row = 0; Row < Capacity.HorizontalCapacity; Row++)
		{
			StorageGrid->SetRowFill(Row, 1.f);

			if (Inventory.Num() - 1 >= Iter)
			{
				UBaseCellUserWidget* CellWidgetRef = CreateWidget<UBaseCellUserWidget>(this, SourceComponent->StorageCellClass);
				CellWidgetRef->InitializeWidget(Inventory[Iter], this);
				StorageGrid->AddChildToGrid(CellWidgetRef, Row, Column)->SetPadding(FMargin(10.f));
			}
			else
			{
				UUserWidget* CellBase = CreateWidget<UUserWidget>(this, BaseCellClass);
				StorageGrid->AddChildToGrid(CellBase, Row, Column)->SetPadding(FMargin(10.f));
			}

			Iter++;
		}
	}
	OwnerComponent = SourceComponent;
	return StorageGrid;
}

void UStorageWidget::OnItemSelected(IUsableInterface* InInterface)
{
	OwnerComponent->OnSelectItem(InInterface);
}
