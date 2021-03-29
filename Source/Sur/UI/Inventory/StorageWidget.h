// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StorageWidget.generated.h"

class USizeBox;
class UGridPanel;
class UBaseCellUserWidget;
class IUsableInterface;
class UItemViewWindow;

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
	UGridPanel* StorageGrid;

	UPROPERTY(meta = (BindWidget))
	USizeBox* ViewPanelBox;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UItemViewWindow> ViewPanelWidgetClass;

public:

	void OnItemSelected(IUsableInterface* InInterface);

	void InitializeWidget(TArray<IUsableInterface*> InInventory, int HorizontalGrid, int VerticalGrid);


};