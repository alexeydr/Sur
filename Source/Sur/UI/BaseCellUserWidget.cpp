// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/BaseCellUserWidget.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Sur/Data Assets/DataAssetForStorage.h"
#include "Sur/UI/Inventory/StorageWidget.h"

void UBaseCellUserWidget::InitializeWidget(IUsableInterface* InInterface, UStorageWidget* InParentWidget)
{
	ItemInterface = InInterface;
	ParentWidget = InParentWidget;
    if (InInterface)
    {
		Icon->SetBrushFromTexture(InInterface->GetUsableDataAsset()->Thumbnail);
		SetToolTipText(FText::FromString(InInterface->GetUsableDataAsset()->Name));
    }    
}

void UBaseCellUserWidget::OnSelect()
{
    if (ParentWidget)
    {
        ParentWidget->OnItemSelected(ItemInterface);
    }
}

void UBaseCellUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

    if(SelectButton)
    {
		SelectButton->OnClicked.AddDynamic(this, &UBaseCellUserWidget::OnSelect);
    }
    
}
