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
};
