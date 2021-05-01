// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SurTypes.generated.h"

/**
 * 
 */

USTRUCT()
struct FStorageSize
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere)
	int VerticalCapacity = 1;

	UPROPERTY(EditAnywhere)
	int HorizontalCapacity = 1;

	FStorageSize() = default;

	FStorageSize(int InVerticalCapacity, int InHorizontalCapacity)
		: VerticalCapacity(InVerticalCapacity), HorizontalCapacity(InHorizontalCapacity) {}

	FStorageSize(int InCapacity)
		: VerticalCapacity(InCapacity), HorizontalCapacity(InCapacity) {}

	int GetStorageSize() { return VerticalCapacity * HorizontalCapacity; }

};


class SurTypes
{
public:

};
