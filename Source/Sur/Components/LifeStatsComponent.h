// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeStatsComponent.generated.h"

#define LIMIT 100.f

class ULifeStatsWidget;
class ASurCharacter;

UENUM()
enum EStat
{
	Health = 0,
	Thrust = 1,
	Hunger = 2
};

USTRUCT()
struct FLifeStats
{
	GENERATED_USTRUCT_BODY()

protected:

	UPROPERTY(Transient)
	float Health = 90.f;

	UPROPERTY(Transient)
	float Thrust = 100.f;

	UPROPERTY(Transient)
	float Hunger = 50.f;

public:

	void AddStat(EStat StatType, float NewValue)
	{
		float* Param = GetStat(StatType);
		*Param += NewValue;
	};

	bool CheckCorrectValue(EStat StatType, float NewValue)
	{
		if (*GetStat(StatType) + NewValue > LIMIT)
			return true;

		return false;
	}

	float* GetStat(EStat StatType) 
	{
		switch (StatType)
		{
		case EStat::Health:
			return &Health;
			break;
		case EStat::Hunger:
			return &Hunger;
			break; 
		case EStat::Thrust:
			return &Thrust;
			break;
		}
		return nullptr;
	};

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUR_API ULifeStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULifeStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(Transient)
	FLifeStats PlayerStat;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ULifeStatsWidget> LifeStatWidgetClass;

	UPROPERTY(Transient)
	ULifeStatsWidget* LifeStatWidgetRef;
	
	UPROPERTY(Transient)
	ASurCharacter* MainChar;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
