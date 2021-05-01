// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Sur/UI/InteractionWidget.h"
#include "Sur/SurCharacter.h"
#include "Sur/Data Assets/UsableDataAsset.h"
#include "Sur/Components/LifeStatsComponent.h"
#include "Sur/Components/CharacterInventoryComponent.h"
#include "Camera/CameraComponent.h"

void APickUpActor::BeginPlay()
{
	Super::BeginPlay();
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

void APickUpActor::OnUse()
{
	if (UsableDataAsset && SurChar->GetLifeStatsComponent() && SurChar->GetInventoryComponent())
	{
		SurChar->GetLifeStatsComponent()->AddStats(UsableDataAsset->GetDeltaEffect());
		SurChar->GetInventoryComponent()->RemoveItemFromInventory(this);
	}
}

void APickUpActor::OnDrop()
{
	if (SurChar->GetInventoryComponent())
	{
		ShowInWorld();
		SurChar->GetInventoryComponent()->RemoveItemFromInventory(this);
	}
}
