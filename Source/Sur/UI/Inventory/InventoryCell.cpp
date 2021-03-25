// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/Inventory/InventoryCell.h"
#include "Kismet/GameplayStatics.h"
#include "Sur/Components/InventoryComponent.h"
#include "Components/Button.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "Sur/SurCharacter.h"

void UInventoryCell::NativeConstruct()
{
	Super::NativeConstruct();

    if (Use && Drop)
    {
		Use->OnClicked.AddDynamic(this, &UInventoryCell::OnUseClicked);
		Drop->OnClicked.AddDynamic(this, &UInventoryCell::OnDropClicked);
    }

}

void UInventoryCell::OnUseClicked()
{
	ItemInterface->OnUse();
}

void UInventoryCell::OnDropClicked()
{
	ItemInterface->OnDrop();
}
