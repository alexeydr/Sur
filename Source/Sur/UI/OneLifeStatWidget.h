// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OneLifeStatWidget.generated.h"

enum EStat;
class UTextBlock;
class UProgressBar;

/**
 * 
 */
UCLASS()
class SUR_API UOneLifeStatWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ParamName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ValueInPercentage;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ValueInProgressBar;

public:

	void SetValueOnWidget(EStat Stat, float Value);

};
