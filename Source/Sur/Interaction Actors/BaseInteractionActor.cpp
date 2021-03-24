// Fill out your copyright notice in the Description page of Project Settings.


#include "Sur/Interaction Actors/BaseInteractionActor.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Sur/UI/InteractionWidget.h"

// Sets default values
ABaseInteractionActor::ABaseInteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseInteractionActor::BeginPlay()
{
	Super::BeginPlay();
   
	WidgetComponent = Cast<UWidgetComponent>(FindComponentByClass(UWidgetComponent::StaticClass()));
	InteractWidget = Cast<UInteractionWidget>(WidgetComponent->GetUserWidgetObject());
    
}

// Called every frame
void ABaseInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseInteractionActor::OnBecameActive()
{
    if (WidgetComponent)
    {
		WidgetComponent->SetVisibility(true);
    }
}

void ABaseInteractionActor::OnStoppedActive()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetVisibility(false);
	}
}

