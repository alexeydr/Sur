// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/CraftActor.h"
#include "Sur/Components/WaitingComponent.h"
#include "Sur/Components/StorageInventoryComponent.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Sur/Components/InventoryComponent.h"
#include "Sur/UI/Craft/CraftWidget.h"
#include "Blueprint/UserWidget.h"

ACraftActor::ACraftActor()
{
	WaitingComp = CreateDefaultSubobject<UWaitingComponent>(TEXT("WaitingComp"));
}

void ACraftActor::BeginPlay()
{
	Super::BeginPlay();
	WaitingComp->OnInteractionTimeComplete.AddDynamic(this, &ACraftActor::OnItemCrated);
}

void ACraftActor::OnItemCrated()
{
	for (auto Temp : ResultCraft)
	{
		APickUpActor* Act = GetWorld()->SpawnActor<APickUpActor>(Temp, GetActorLocation() + FVector(0, 0, 500), FRotator());
		Act->GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
}

void ACraftActor::OnPlayerStartCraft(FRecipe* ExpectedResult)
{
    if (ExpectedResult)
    {
		InventoryComp->ClearInventory();
		WaitingComp->ItemUsed(ExpectedResult->CraftTime);
		ResultCraft = ExpectedResult->Result;
    }
}

void ACraftActor::OnInteraction()
{	
	Super::OnInteraction();

	UCraftWidget* CraftWidgetRef = Cast<UCraftWidget>(InventoryComp->GetStorageWidget());
    if (CraftWidgetRef)
    {
		CraftWidgetRef->InitializeWidget(this);
    }
		
	
}

