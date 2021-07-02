// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sur/Data Assets/CraftDataAsset.h"
#include "Sur/UI/Inventory/StorageWidget.h"
#include "CraftWidget.generated.h"

class UInventoryComponent;
class APickUpActor;
class ACraftActor;
class UButton;

UCLASS()
class SUR_API UCraftWidget : public UStorageWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UButton* CreateItem;

	void InitializeWidget(ACraftActor* InOwner);

protected:

	UFUNCTION()
	void OnCraftItem();

    UPROPERTY()
	FRecipe CurrentRecipe;

	UPROPERTY()
	ACraftActor* Owner;

	virtual void OnItemSelected(IUsableInterface* InInterface) override;
    
};
