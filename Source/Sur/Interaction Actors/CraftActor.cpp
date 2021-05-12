// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/CraftActor.h"
#include "Sur/Components/WaitingComponent.h"
#include "Sur/Components/StorageInventoryComponent.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "Components/VerticalBox.h"

ACraftActor::ACraftActor()
{
	WaitingComp = CreateDefaultSubobject<UWaitingComponent>(TEXT("WaitingComp"));
}

void ACraftActor::BeginPlay()
{
	Super::BeginPlay();
	InventoryComp->OnItemAddToStorage.AddDynamic(this, &ACraftActor::OnPlayerAddItem);
	//WaitingComp->OnInteractionTimeComplete.AddDynamic(this, &APickUpActor::UseItem);
}

void ACraftActor::OnPlayerAddItem(APickUpActor* ItemForAdd)
{

}

void ACraftActor::OnInteraction()
{	
	Super::OnInteraction();
	if (InventoryComp->GetStorageWidget())
	{
		UStorageWidget* StorageWidgetRef = InventoryComp->GetStorageWidget();
		UVerticalBox* MainContainer = NewObject<UVerticalBox>();
	}
}

void ACraftActor::OnUse()
{
	
}

void ACraftActor::OnDrop()
{

}
