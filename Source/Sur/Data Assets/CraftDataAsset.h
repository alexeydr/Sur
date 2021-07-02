// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CraftDataAsset.generated.h"

class APickUpActor;

USTRUCT(BlueprintType)
struct FRecipe
{
    GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<UObject*> Source;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<APickUpActor>> Result;

	UPROPERTY(EditAnywhere)
	float CraftTime;

};

UCLASS()
class SUR_API UCraftDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere)
	TArray<FRecipe> Recipes;

};
