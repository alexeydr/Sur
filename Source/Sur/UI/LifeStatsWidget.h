// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LifeStatsWidget.generated.h"

enum EStat;
class UVerticalBox;
class UOneLifeStatWidget;

/**
 * 
 */
UCLASS()
class SUR_API ULifeStatsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(Transient)
	TMap<TEnumAsByte<EStat>, UOneLifeStatWidget*> AllWidgets;
	
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ParamName;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UOneLifeStatWidget> ContentClass;

public:

	void UpdateWidget(EStat ValueType, float NewValue);
	
	void CreateStatRow(EStat ValueType, float Value);

};
