// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Sur/Interaction Actors/BaseInteractionActor.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "PickUpActor.generated.h"

class UDataAssetForStorage;
class UBaseCellUserWidget;
class UUsableDataAsset;
class UWaitingComponent;
/**
 * 
 */
UCLASS()
class SUR_API APickUpActor : public ABaseInteractionActor, public IUsableInterface 
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UWaitingComponent* WaitingComp;

	UPROPERTY(EditAnywhere)
	UDataAssetForStorage* StorageDataAsset;

	UPROPERTY(EditAnywhere)
	UUsableDataAsset* UsableDataAsset;	

	UPROPERTY(EditAnywhere)
	float DistanceToDrop = 50.f;

	UFUNCTION()
	void UseItem();

public:

	APickUpActor();

	void HideInWorld();

    void ShowInWorld();

	//IInteractionInterface interface

	virtual float GetInteractionTime() override { return InteractionTime; }

	virtual AActor* GetOwningActor() override { return this; }

	virtual void OnStoppedActive() override { Super::OnStoppedActive(); };

	virtual void OnInteraction() override;

	//End of IInteractionInterface interface


	//IUsableInterface interface

	virtual float GetUsingTime() override;

	virtual UDataAssetForStorage* GetUsableDataAsset() override { return StorageDataAsset; }

	virtual void OnUse() override;

	virtual void OnDrop() override;

	//End of IUsableInterface interface
	
};
