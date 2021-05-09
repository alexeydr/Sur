// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Interaction Actors/CraftActor.h"
#include "Sur/Components/WaitingComponent.h"

ACraftActor::ACraftActor()
{
	WaitingComp = CreateDefaultSubobject<UWaitingComponent>(TEXT("WaitingComp"));
}

void ACraftActor::BeginPlay()
{
	Super::BeginPlay();
	//WaitingComp->OnInteractionTimeComplete.AddDynamic(this, &APickUpActor::UseItem);
}

void ACraftActor::OnInteraction()
{
	Super::OnInteraction();

}

void ACraftActor::OnUse()
{

}

void ACraftActor::OnDrop()
{

}
