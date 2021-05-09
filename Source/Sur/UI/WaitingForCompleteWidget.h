// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaitingForCompleteWidget.generated.h"

class UWaitingComponent;
class UProgressBar;

UCLASS()
class SUR_API UWaitingForCompleteWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

    virtual void NativeDestruct() override;

    UPROPERTY(meta = (BindWidget))
	UProgressBar* RemainingTimeProgressBar;

	UFUNCTION()
	float GetRemainingPercent();

	UFUNCTION()
	void OnTimerComplete() { RemoveFromParent(); }

    UPROPERTY(Transient)
	UWaitingComponent* OwnerWaitingComp;
public:

	void SetRemainingTime(UWaitingComponent* WaitingComp);
	
};
