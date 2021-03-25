// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/UI/BaseCellUserWidget.h"
#include "InventoryCell.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class SUR_API UInventoryCell : public UBaseCellUserWidget
{
	GENERATED_BODY()

protected:


	UPROPERTY(meta = (BindWidget))
	UButton* Use;

	UPROPERTY(meta = (BindWidget))
	UButton* Drop;

	UFUNCTION()
	void OnUseClicked();

	UFUNCTION()
	void OnDropClicked();

	virtual void NativeConstruct() override;

};
