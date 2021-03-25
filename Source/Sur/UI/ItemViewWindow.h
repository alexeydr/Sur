// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemViewWindow.generated.h"

class IUsableInterface;
class UButton;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class SUR_API UItemViewWindow : public UUserWidget
{
	GENERATED_BODY()

public:

	void InitializeWidget(IUsableInterface* InInterface);

    UPROPERTY(meta = (BindWidget))
	UTextBlock* Description;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	UButton* Drop;

    UPROPERTY(meta = (BindWidget))
	UButton* Use;

	IUsableInterface* Interface;

	UFUNCTION()
	void OnUseClicked();

	UFUNCTION()
	void OnDropClicked();
};

