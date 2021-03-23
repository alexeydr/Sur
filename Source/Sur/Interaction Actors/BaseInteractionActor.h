// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sur/Interfaces/InteractionInterface.h"
#include "BaseInteractionActor.generated.h"

class UWidgetComponent;

UCLASS()
class ABaseInteractionActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInteractionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual AActor* GetOwningActor() override { return this; }

	virtual void OnBecameActive() override;

	virtual void OnStoppedActive() override;
};
