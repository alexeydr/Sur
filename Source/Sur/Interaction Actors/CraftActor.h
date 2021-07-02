// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sur/Interaction Actors/BaseStorageActor.h"
#include "Sur/Interfaces/UsableInterface.h"
#include "CraftActor.generated.h"

struct FRecipe;
class UWaitingComponent;
class APickUpActor;
class UCraftDataAsset;
class UUserWidget;
class UInventoryComponent;
class UCraftWidget;

UCLASS()
class SUR_API ACraftActor : public ABaseStorageActor, public IUsableInterface
{
	GENERATED_BODY()

public:

	ACraftActor();

protected:
	
	UPROPERTY(EditDefaultsOnly)
	UCraftDataAsset* CraftDataAsset;

	UPROPERTY(EditDefaultsOnly)
	UWaitingComponent* WaitingComp;

    virtual void BeginPlay() override;

	UFUNCTION()
	void OnItemCrated();

    UPROPERTY()
	TArray<TSubclassOf<APickUpActor>> ResultCraft;

public:

	void OnPlayerStartCraft(FRecipe* ExpectedResult);

	UCraftDataAsset* GetCraftDA() const { return CraftDataAsset; }

	//IInteractionInterface interface

	virtual void OnInteraction() override;

	//End of IInteractionInterface interface
	
    //IUsableInterface interface

	virtual void OnUse() override {};

	virtual void OnDrop() override {};

	//End of IUsableInterface interface
	
};
