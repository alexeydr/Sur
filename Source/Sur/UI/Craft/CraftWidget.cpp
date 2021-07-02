// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/Craft/CraftWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Sur/Interaction Actors/CraftActor.h"
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Sur/Components/StorageInventoryComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Sur/Components/InventoryComponent.h"
#include "Sur/Data Assets/CraftDataAsset.h"
#include "Sur/Library.h"
#include "Components/Button.h"

void UCraftWidget::InitializeWidget(ACraftActor* InOwner)
{
	if (InOwner && CreateItem)
	{
		Owner = InOwner;
		CreateItem->OnClicked.AddDynamic(this, &UCraftWidget::OnCraftItem);
	}
}

void UCraftWidget::OnCraftItem()
{
    if (!Owner)
        return;

	Owner->OnPlayerStartCraft(&CurrentRecipe);
}

void UCraftWidget::OnItemSelected(IUsableInterface* InInterface)
{
	Super::OnItemSelected(InInterface);
	CreateItem->SetIsEnabled(false);
	for (FRecipe CurrRec : Owner->GetCraftDA()->Recipes)
	{
		const bool HasItems = !Library::ContainsSubArrayInArray<AActor*>(reinterpret_cast<TArray<AActor*>&>(CurrRec.Source), reinterpret_cast<TArray<AActor*>&>(OwnerComponent->GetInventory()));
		if (HasItems)
		{
			CurrentRecipe = CurrRec;
			CreateItem->SetIsEnabled(true);
			break;
		}
	}
}
