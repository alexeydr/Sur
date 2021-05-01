// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseCellUserWidget.generated.h"

class IUsableInterface;
class UImage;
class UButton;
class UStorageWidget;
/**
 * 
 */
UCLASS()
class SUR_API UBaseCellUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void InitializeWidget(IUsableInterface* InInterface, UStorageWidget* InParentWidget);

protected:

	UFUNCTION()
	void OnSelect();

    virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UImage* Icon;

    UPROPERTY(meta = (BindWidget))
	UButton* SelectButton;

	IUsableInterface* ItemInterface;

	UStorageWidget* ParentWidget;

};
