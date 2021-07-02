// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sur/Interfaces/InteractionInterface.h"
#include "BaseInteractionActor.generated.h"

class UWidgetComponent;
class UInteractionWidget;
class ASurCharacter;

UCLASS()
class ABaseInteractionActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:

	ABaseInteractionActor();

    UPROPERTY(Transient)
	ASurCharacter* SurChar;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InteractionTime;

	UPROPERTY(Transient)
	UInteractionWidget* InteractWidget;

	UPROPERTY(EditAnywhere)
	FString TextOnInteractionWidget;

public:

	UStaticMeshComponent* GetMesh() { return MeshComponent; };

	virtual void Tick(float DeltaTime) override;

	//IInteractionInterface interface

	virtual float GetInteractionTime() override { return InteractionTime; }

	virtual AActor* GetOwningActor() override { return this; }

	virtual void OnBecameActive() override;

	virtual void OnStoppedActive() override;

	//End of IInteractionInterface interface
};
