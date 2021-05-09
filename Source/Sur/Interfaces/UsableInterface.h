// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UsableInterface.generated.h"

class UDataAssetForStorage;

UINTERFACE(MinimalAPI)
class UUsableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SUR_API IUsableInterface
{
	GENERATED_BODY()

public:

	virtual float GetUsingTime() { return 0.f; }

	virtual UDataAssetForStorage* GetUsableDataAsset() { return nullptr; }

	virtual void OnUse() {}

	virtual void OnDrop() {}
};
