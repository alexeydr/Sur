// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/Inventory/StorageWidget.h"
#include "Components/GridPanel.h"
#include "Components/SizeBox.h"
#include "Sur/UI/BaseCellUserWidget.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "Sur/UI/ItemViewWindow.h"
#include "Components/GridSlot.h"


void UStorageWidget::InitializeWidget(TArray<IUsableInterface*> InInventory, int HorizontalGrid, int VerticalGrid)
{
	StorageGrid->ClearChildren();
	int Iter = 0;
	for (int Column = 0; Column < VerticalGrid; Column++)
	{
		StorageGrid->SetColumnFill(Column, 1.f);
		for (int Row = 0; Row < HorizontalGrid; Row++)
		{
			StorageGrid->SetRowFill(Row, 1.f);

		    UBaseCellUserWidget* CellWidgetRef = nullptr;
			UUserWidget* CellBase = nullptr;
            if (InInventory.Num() - 1 >= Iter)
            {
				CellWidgetRef = CreateWidget<UBaseCellUserWidget>(this, InInventory[Iter]->GetStorageCellSubclass());
				CellWidgetRef->InitializeWidget(InInventory[Iter],this);
            }
            else
            {
				CellBase = CreateWidget<UUserWidget>(this, BaseCellClass);
            }

			Iter++;
			StorageGrid->AddChildToGrid(IsValid(CellWidgetRef) ? CellWidgetRef : CellBase, Row, Column)->SetPadding(FMargin(10.f));
		
		}
	}
}

void UStorageWidget::OnItemSelected(IUsableInterface* InInterface)
{
    if (ViewPanelBox && ViewPanelWidgetClass)
    {
		ViewPanelBox->ClearChildren();
		UItemViewWindow* ViewPanelRef = CreateWidget<UItemViewWindow>(this, ViewPanelWidgetClass);
		ViewPanelRef->InitializeWidget(InInterface);
		ViewPanelBox->AddChild(ViewPanelRef);
    }
}