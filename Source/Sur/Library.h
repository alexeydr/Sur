// Fill out your copyright notice in the Description page of Project Settings
#pragma once

#include "CoreMinimal.h"

class UCharacterInventoryComponent;
/**
 * 
 */
class SUR_API Library
{
public:

	static FString EnumToString(const TCHAR* EnumPtr, int32 EnumValue);

	static UCharacterInventoryComponent* GetCharacterInventory(UObject* WCO);

    template<class Type>
	static bool ContainsSubArrayInArray(TArray<Type> Array, TArray<Type> SubArray)
    {
		bool Result = false;
		for (int i = 0; i < (Array.Num() - SubArray.Num() + 1); i++)
		{
			Result = true;
			for (int j = 0; j < SubArray.Num(); j++)
			{
				if (Array[i + j] != SubArray[j])
				{
					Result = false;
					break;
				}
			}
		}
		return Result;
    };
};
