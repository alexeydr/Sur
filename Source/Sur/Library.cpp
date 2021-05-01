// Fill out your copyright notice in the Description page of Project Settings.
#include "Library.h"
#include "Kismet/GameplayStatics.h"
#include "Sur/SurCharacter.h"
#include "Sur/Components/CharacterInventoryComponent.h"

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

UCharacterInventoryComponent* Library::GetCharacterInventory(UObject* WCO)
{
	ASurCharacter* MainChar = Cast<ASurCharacter>(UGameplayStatics::GetPlayerCharacter(WCO, 0));
	return MainChar->GetInventoryComponent();
}
