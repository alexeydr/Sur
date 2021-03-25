// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/PickUpActor.h"
#include "Sur/UI/InteractionWidget.h"
#include "Sur/SurCharacter.h"
#include "Sur/Components/InventoryComponent.h"
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
	FVector ForwardVector = SurChar->GetActorForwardVector();
	FVector End = ForwardVector * 15.f + Start;
	TeleportTo(End,GetActorRotation());

	this->SetActorHiddenInGame(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickUpActor::OnBecameActive()
{
	Super::OnBecameActive();
	InteractWidget->SetTextOnWidget("pick up");
}

void APickUpActor::OnInteraction()
{
	SurChar->GetInventoryComponent()->AddItem(this);
}

void APickUpActor::OnUse()
{
	SurChar->GetInventoryComponent()->RemoveItemFromInventory(this);
}

void APickUpActor::OnDrop()
{
	ShowInWorld();
	SurChar->GetInventoryComponent()->RemoveItemFromInventory(this);
}
