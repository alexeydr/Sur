// Fill out your copyright notice in the Description page of Project Settings.
#include "Sur/Components/LifeStatsComponent.h"
#include "Sur/UI/LifeStatsWidget.h"
#include "Blueprint/UserWidget.h"
#include "Sur/SurCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
ULifeStatsComponent::ULifeStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULifeStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	MainChar = Cast<ASurCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (LifeStatWidgetClass)
	{
		LifeStatWidgetRef = CreateWidget<ULifeStatsWidget>(UGameplayStatics::GetGameInstance(GetWorld()), LifeStatWidgetClass);
		LifeStatWidgetRef->CreateStatRow(EStat::Health, *PlayerStat.GetStat(EStat::Health)); 
		LifeStatWidgetRef->CreateStatRow(EStat::Hunger, *PlayerStat.GetStat(EStat::Hunger));
		LifeStatWidgetRef->CreateStatRow(EStat::Thrust, *PlayerStat.GetStat(EStat::Thrust));
		LifeStatWidgetRef->AddToViewport();
	}
	FTimerHandle TH;
	GetWorld()->GetTimerManager().SetTimer(TH, this, &ULifeStatsComponent::OnSubstractLifeStats, 1.f, true);
	// ...
	
}

void ULifeStatsComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	
}


void ULifeStatsComponent::CheckValueOnMainStat()
{
	if (FMath::IsNearlyZero(*PlayerStat.GetStat(EStat::Health)))
	{
		Die();
	}
}

void ULifeStatsComponent::CheckValueOnAdditionalStat()
{
	if (FMath::IsNearlyZero(*PlayerStat.GetStat(EStat::Hunger)) || 
		FMath::IsNearlyZero(*PlayerStat.GetStat(EStat::Thrust)))
	{
		PlayerStat.ChangeStat(EStat::Health, -0.1f);
	}
}

void ULifeStatsComponent::Die()
{
	if (MainChar)
	{
		MainChar->Destroy();
	}
}

void ULifeStatsComponent::OnSubstractLifeStats()
{
	PlayerStat.ChangeStat(EStat::Hunger, -1.f);
	PlayerStat.ChangeStat(EStat::Thrust, -1.f);

	CheckValueOnAdditionalStat();
	CheckValueOnMainStat();

	if (LifeStatWidgetRef)
	{
		LifeStatWidgetRef->UpdateWidget(EStat::Hunger, *PlayerStat.GetStat(EStat::Hunger));
		LifeStatWidgetRef->UpdateWidget(EStat::Thrust, *PlayerStat.GetStat(EStat::Thrust));
		LifeStatWidgetRef->UpdateWidget(EStat::Health, *PlayerStat.GetStat(EStat::Health));
	}
	
}

// Called every frame
void ULifeStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

