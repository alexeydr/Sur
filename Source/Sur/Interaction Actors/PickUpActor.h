// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Interaction Actors/BaseInteractionActor.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "PickUpActor.generated.h"

class UDataAssetForStorage;
class UBaseCellUserWidget;
/**
 * 
 */
UCLASS()
class SUR_API APickUpActor : public ABaseInteractionActor, public IUsableInterface 
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UDataAssetForStorage* StorageDataAsset;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBaseCellUserWidget> CellClass;

public:

	void HideInWorld();

    void ShowInWorld();

	//IInteractionInterface interface

	virtual float GetInteractionTime() override { return InteractionTime; }

	virtual AActor* GetOwningActor() override { return this; }

	virtual void OnBecameActive() override;
    
	virtual void OnStoppedActive() override { Super::OnStoppedActive(); };

	virtual void OnInteraction() override;

	//End of IInteractionInterface interface


	//IUsableInterface interface

	virtual UDataAssetForStorage* GetUsableDataAsset() override { return StorageDataAsset; }

	virtual TSubclassOf<UBaseCellUserWidget> GetStorageCellSubclass() override { return CellClass; }

	virtual void OnUse() override;

	virtual void OnDrop() override;

	//End of IUsableInterface interface
	
};
