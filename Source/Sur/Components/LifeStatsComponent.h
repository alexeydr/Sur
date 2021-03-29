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

	UPROPERTY(EditAnywhere)
	float Health = 90.f;

	UPROPERTY(EditAnywhere)
	float Thrust = 100.f;

	UPROPERTY(EditAnywhere)
	float Hunger = 50.f;

public:
	
	void ChangeStat(EStat StatType, float NewValue)
	{
		float* Param = GetStat(StatType);
		*Param += NewValue;
		*Param = FMath::Clamp(*Param, 0.f, LIMIT);
	};

	float* GetStat(EStat StatType) 
	{
		switch (StatType)
		{
		case EStat::Health:
			return &Health;
		case EStat::Hunger:
			return &Hunger;
		case EStat::Thrust:
			return &Thrust;
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

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(Transient)
	FLifeStats PlayerStat;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ULifeStatsWidget> LifeStatWidgetClass;

	UPROPERTY(Transient)
	ULifeStatsWidget* LifeStatWidgetRef;
	
	UPROPERTY(Transient)
	ASurCharacter* MainChar;

	void CheckValueOnMainStat();

	void CheckValueOnAdditionalStat();

	void Die();
	
	UFUNCTION()
	void OnSubstractLifeStats();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
