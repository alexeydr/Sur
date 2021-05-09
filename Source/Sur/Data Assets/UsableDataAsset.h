// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Sur/Components/LifeStatsComponent.h"
#include "UsableDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class SUR_API UUsableDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(EditAnywhere)
	FLifeStats PositiveEffect;

	UPROPERTY(EditAnywhere)
	FLifeStats NegativeEffect;

	FLifeStats GetDeltaEffect() { return PositiveEffect + NegativeEffect; }

	UPROPERTY(EditAnywhere)
	float UsingTime = 1.f;

};
