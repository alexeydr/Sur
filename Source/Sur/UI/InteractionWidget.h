// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class UInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetTextOnWidget(FString InInteractionAction, FString InInteractionTimeText = "");

protected:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* InteractionText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* InteractionTimeText;
	
};
