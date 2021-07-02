// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Sur/Interaction Actors/PickUpActor.h"
#include "GameFramework/Character.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Sur/SurCharacter.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bIsOpenned = false;
	// ...
}

void UInventoryComponent::CreateWidgetInventory()
{   
	if (!bIsOpenned)
	{
		StorageWidgetRef = CreateWidget<UStorageWidget>(GetWorld(), InventoryWidgetClass);
		if (StorageWidgetRef)
		{
			bIsOpenned = true;
			StorageWidgetRef->AddToViewport();
		}
	}
	else
	{
		bIsOpenned = false;
		StorageWidgetRef->RemoveFromParent();
	}
}

void UInventoryComponent::RemoveItemFromInventory(APickUpActor* Item)
{
    if (Inventory.Contains(Item))
    {
		Inventory.Remove(Item);

		if (OnItemRemoveFromStorage.IsBound())
			OnItemRemoveFromStorage.Broadcast(Item, this);
    }
}

void UInventoryComponent::AddItem(APickUpActor* NewItem)
{
    if (Inventory.Num() < InventoryCapacity.GetStorageSize())
    {
		Inventory.Add(NewItem);

		if (OnItemAddToStorage.IsBound())
			OnItemAddToStorage.Broadcast(NewItem, this);
      
		NewItem->HideInWorld(); 
		
    }
    else
    {
		UE_LOG(LogTemp, Error, TEXT("Inventory is full"));
    }
}

void UInventoryComponent::ClearInventory()
{

}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

