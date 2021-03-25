// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/UI/InteractionWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/InputSettings.h"

void UInteractionWidget::SetTextOnWidget(FString InInteractionAction, FString InInteractionTimeText)
{
	if (auto Settings = UInputSettings::GetInputSettings())
	{
		TArray<FInputActionKeyMapping> InputKeyMap;
		Settings->GetActionMappingByName(FName("Interaction"), InputKeyMap);

        // -------- Текст в виджете взаимодействия
		InteractionText->SetText(FText::FromString("Press " + InputKeyMap.Last().Key.ToString() + " to " + InInteractionAction));
        InteractionTimeText->SetText(FText::FromString(InInteractionTimeText));
		
	}
}
