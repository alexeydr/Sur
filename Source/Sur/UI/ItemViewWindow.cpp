// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/ItemViewWindow.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "Sur/Data Assets/DataAssetForStorage.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


void UItemViewWindow::InitializeWidget(IUsableInterface* InInterface)
{
	Interface = InInterface;
	UDataAssetForStorage* DA = InInterface->GetUsableDataAsset();

	Name->SetText(FText::FromString(DA->Name));
	Description->SetText(FText::FromString(DA->Title));
	Icon->SetBrushFromTexture(DA->IconInViewWidnow);

	Use->OnClicked.AddDynamic(this, &UItemViewWindow::OnUseClicked);
	Drop->OnClicked.AddDynamic(this, &UItemViewWindow::OnDropClicked);
}

void UItemViewWindow::OnUseClicked()
{
	Interface->OnUse();
	RemoveFromParent();
}

void UItemViewWindow::OnDropClicked()
{
	Interface->OnDrop();
	RemoveFromParent();
}
