// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class APickUpActor;
class UStorageWidget;
class IUsableInterface;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUR_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UStorageWidget> InventoryWidgetClass;

	void OnCharUseInventory();

	void RemoveItemFromInventory(APickUpActor* Item);

	void AddItem(APickUpActor* NewItem);

	int GetMaxInventoryCapacity() const { return InventoryHorizontalCapacity * InventoryVerticalCapacity; }


protected:

	virtual void BeginPlay() override;

	UPROPERTY(Transient)
	uint8 bIsOpenned : 1;

	TArray<IUsableInterface*> Inventory;

	UPROPERTY(Transient)
	UStorageWidget* StorageWidgetRef;

	UPROPERTY(EditAnywhere)
	int InventoryHorizontalCapacity = 1;

	UPROPERTY(EditAnywhere)
	int InventoryVerticalCapacity = 1;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
