// Fill out your copyright notice in the Description page of Project Settings.


#include "Library.h"

FString Library::EnumToString(const TCHAR* Enum, int32 EnumValue)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, Enum, true);
	if (EnumPtr)
	{
		if (WITH_EDITOR)
		{
			return EnumPtr->GetDisplayNameText(EnumValue).ToString();
		}
		else
		{
			return EnumPtr->GetEnumName(EnumValue);
		}
	}

	return FString("Invalid value");
}
