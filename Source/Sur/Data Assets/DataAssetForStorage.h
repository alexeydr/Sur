// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAssetForStorage.generated.h"

/**
 * 
 */
UCLASS()
class SUR_API UDataAssetForStorage : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* IconInViewWidnow;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Thumbnail;

	UPROPERTY(EditDefaultsOnly)
	FString Title;


};
