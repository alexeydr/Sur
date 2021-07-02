// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Components/WaitingComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "Sur/UI/WaitingForCompleteWidget.h"
// Sets default values for this component's properties
UWaitingComponent::UWaitingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWaitingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UWaitingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	OnInteractionTimeComplete.Clear();
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	}
	Super::EndPlay(EndPlayReason);
   
}

void UWaitingComponent::ItemUsed(float UseTime)
{
    if (WaitingWidgetClass && !GetWorld()->GetTimerManager().IsTimerActive(CurrentTH))
    {
		UWaitingForCompleteWidget* WaitingWidget = CreateWidget<UWaitingForCompleteWidget>(GetWorld(), WaitingWidgetClass);
		GetWorld()->GetTimerManager().SetTimer(CurrentTH, this, &UWaitingComponent::OnTimerComplete, UseTime, false);
        if (WaitingWidget)
        {
			WaitingWidget->SetRemainingTime(this);
			WaitingWidget->AddToViewport();
        }
    }
}

// Called every frame
void UWaitingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

