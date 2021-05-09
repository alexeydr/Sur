// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WaitingComponent.generated.h"

class IUsableInterface;
class UWaitingForCompleteWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionTimeComplete);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUR_API UWaitingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWaitingComponent();

	FOnInteractionTimeComplete OnInteractionTimeComplete;

	FTimerHandle CurrentTH;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UWaitingForCompleteWidget> WaitingWidgetClass;

	UFUNCTION()
	void OnTimerComplete()
	{
		if (OnInteractionTimeComplete.IsBound())
			OnInteractionTimeComplete.Broadcast();
	};

public:

	void ItemUsed(float UseTime);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
