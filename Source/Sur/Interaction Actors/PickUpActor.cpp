// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Sur/UI/InteractionWidget.h"
#include "Sur/SurCharacter.h"
#include "Sur/Data Assets/UsableDataAsset.h"
#include "Sur/Components/LifeStatsComponent.h"
#include "Sur/Components/WaitingComponent.h"
#include "Sur/Components/CharacterInventoryComponent.h"
#include "Camera/CameraComponent.h"

APickUpActor::APickUpActor()
{
	WaitingComp = CreateDefaultSubobject<UWaitingComponent>(TEXT("WaitingComp"));
}

void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
	WaitingComp->OnInteractionTimeComplete.AddDynamic(this, &APickUpActor::UseItem);
}

void APickUpActor::HideInWorld()
{
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	this->SetActorHiddenInGame(true);
}

void APickUpActor::ShowInWorld()
{
	FVector Start = SurChar->GetActorLocation();
	FVector ForwardVector = SurChar->GetActorForwardVector().GetSafeNormal();
	FVector End = ForwardVector * DistanceToDrop + Start;
	TeleportTo(End,GetActorRotation());

	this->SetActorHiddenInGame(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickUpActor::OnInteraction()
{
	if (SurChar->GetInventoryComponent())
	{
		SurChar->GetInventoryComponent()->AddItem(this);
	}
}

void APickUpActor::UseItem()
{
	if (UsableDataAsset && SurChar->GetLifeStatsComponent() && SurChar->GetInventoryComponent())
	{
		SurChar->GetLifeStatsComponent()->AddStats(UsableDataAsset->GetDeltaEffect());
		SurChar->GetInventoryComponent()->RemoveItemFromInventory(this);
	}
}

float APickUpActor::GetUsingTime()
{
	return UsableDataAsset ? UsableDataAsset->UsingTime : 0.f;
}

void APickUpActor::OnUse()
{
	if (FMath::IsNearlyZero(GetUsingTime()))
		UseItem();
    else 
		WaitingComp->ItemUsed(GetUsingTime());
}

void APickUpActor::OnDrop()
{
	if (SurChar->GetInventoryComponent())
	{
		ShowInWorld();
		SurChar->GetInventoryComponent()->RemoveItemFromInventory(this);
	}
}
