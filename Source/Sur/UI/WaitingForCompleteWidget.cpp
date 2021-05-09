// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/WaitingForCompleteWidget.h"
#include "Components/ProgressBar.h"
#include "Sur/Components/WaitingComponent.h"
#include "TimerManager.h"

void UWaitingForCompleteWidget::NativeDestruct()
{
	RemainingTimeProgressBar->PercentDelegate.Clear();
	Super::NativeDestruct();
}

float UWaitingForCompleteWidget::GetRemainingPercent()
{
	if (!OwnerWaitingComp)
		return 0.f;

	const float RemTime = GetWorld()->GetTimerManager().GetTimerRemaining(OwnerWaitingComp->CurrentTH);
	const float Duration = GetWorld()->GetTimerManager().GetTimerElapsed(OwnerWaitingComp->CurrentTH) + RemTime;
	return RemTime / Duration;
}

void UWaitingForCompleteWidget::SetRemainingTime(UWaitingComponent* WaitingComp)
{
	OwnerWaitingComp = WaitingComp;
    if (RemainingTimeProgressBar && WaitingComp)
    {
		WaitingComp->OnInteractionTimeComplete.AddDynamic(this, &UWaitingForCompleteWidget::OnTimerComplete);
		RemainingTimeProgressBar->PercentDelegate.BindUFunction(this, "GetRemainingPercent");
    }
}
