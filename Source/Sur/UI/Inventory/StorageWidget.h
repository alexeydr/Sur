// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StorageWidget.generated.h"

class USizeBox;
class UBaseCellUserWidget;
class UItemViewWindow;
class UInventoryComponent;
class IUsableInterface;
/**
 * 
 */
UCLASS()
class SUR_API UStorageWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> BaseCellClass;

	UPROPERTY(meta = (BindWidget))
	USizeBox* AdditionalBox;

	UPROPERTY(meta = (BindWidget))
	USizeBox* MainBox;

	UPROPERTY(Transient)
	UInventoryComponent* OwnerComponent;

public:

	UWidget* GetWidgetFromAdditionalBox();

	UWidget* GetWidgetFromMainBox();

	void OnItemSelected(IUsableInterface* InInterface);

	UPanelWidget* FormBoxWithCells(UInventoryComponent* SourceComponent);

	void AddToAdditionalWindow(UWidget* Content);

	void AddToMainWindow(UWidget* Content);
};
