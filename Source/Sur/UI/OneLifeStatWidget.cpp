// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/OneLifeStatWidget.h"
#include "Sur/Components/LifeStatsComponent.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Sur/Library.h"

void UOneLifeStatWidget::SetValueOnWidget(EStat Stat, float Value)
{
	ParamName->SetText(FText::FromString(Library::EnumToString(TEXT("EStat"),Stat)));
	ValueInPercentage->SetText(FText::FromString(FString::FromInt(Value)));
	ValueInProgressBar->SetPercent(Value / 100.f);
}
