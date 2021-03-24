// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "UObject/ScriptInterface.h"
#include "InteractionComponent.generated.h"

class ASurCharacter;
class IInteractionInterface;
class UParticleSystemComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUR_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	IInteractionInterface* GetActiveInteractActor() { return ActiveInteractActor; }

protected:

	UPROPERTY(Transient)
	TScriptInterface<IInteractionInterface> LastActiveActor;

	UPROPERTY(Transient)
	float CosInteractionAngle;

	UPROPERTY(EditDefaultsOnly)
	float InteractionAngle;

	UPROPERTY(EditDefaultsOnly)
	float InteractionDistance;

	UPROPERTY(Transient)
	ASurCharacter* OwnerCharacter;

	IInteractionInterface* ActiveInteractActor;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
