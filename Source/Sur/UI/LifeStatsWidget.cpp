// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/LifeStatsWidget.h"
#include "Sur/Components/LifeStatsComponent.h"
#include "Components/VerticalBox.h"
#include "Sur/UI/OneLifeStatWidget.h"
#include "Sur/Library.h"

void ULifeStatsWidget::CreateStatRow(EStat ValueType, float Value)
{
	if (ContentClass)
	{
		UOneLifeStatWidget* WidgetRef = CreateWidget<UOneLifeStatWidget>(this,ContentClass);
		if (WidgetRef)
		{
			WidgetRef->SetValueOnWidget(ValueType, Value);
			ParamName->AddChildToVerticalBox(WidgetRef);
		}
	}
}
