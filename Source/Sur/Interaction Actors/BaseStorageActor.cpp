// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/BaseStorageActor.h"
#include "Sur/Components/StorageInventoryComponent.h"

ABaseStorageActor::ABaseStorageActor()
{
	InventoryComp = CreateDefaultSubobject<UStorageInventoryComponent>(TEXT("StorageComp"));
}

void ABaseStorageActor::OnInteraction()
{
	InventoryComp->CreateWidgetInventory();
}
