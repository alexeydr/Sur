// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sur/SurTypes.h"
#include "InventoryComponent.generated.h"

class APickUpActor;
class UStorageWidget;
class IUsableInterface;
class UBaseCellUserWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUR_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	virtual void CreateWidgetInventory();

	virtual void OnSelectItem(IUsableInterface* SelectedItem) {};

	virtual void RemoveItemFromInventory(APickUpActor* Item);

	virtual void AddItem(APickUpActor* NewItem);

	const TArray<IUsableInterface*>& GetInventory() { return Inventory; }

	const FStorageSize& GetInventoryCapacity() { return InventoryCapacity; }

	UStorageWidget* GetStorageWidget() { return StorageWidgetRef; }

protected:

	virtual void BeginPlay() override;

	UPROPERTY(Transient)
	uint8 bIsOpenned : 1;

	TArray<IUsableInterface*> Inventory;

	UPROPERTY(Transient)
	UStorageWidget* StorageWidgetRef;

	UPROPERTY(EditAnywhere)
	FStorageSize InventoryCapacity = 5;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UStorageWidget> InventoryWidgetClass;

public:	

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBaseCellUserWidget> StorageCellClass;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
