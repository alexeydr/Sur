// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SurCharacter.generated.h"

class IInteractionInterface;
class UInteractionComponent;
class USpringArmComponent;
class UCameraComponent;
class UCharacterInventoryComponent;
class ULifeStatsComponent;
class APickUpActor;

UCLASS(config=Game)
class ASurCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere)
	UInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere)
	UCharacterInventoryComponent* CharInventoryComp;
	
	UPROPERTY(VisibleAnywhere)
	ULifeStatsComponent* LifeStatsComp;

public:

	ASurCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void Interaction();

    UFUNCTION()
	void OnInteractTimerCompleted(TScriptInterface<IInteractionInterface> InInteractActor);

	void UseInventory();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FORCEINLINE UCharacterInventoryComponent* GetInventoryComponent() const { return CharInventoryComp; }

	FORCEINLINE ULifeStatsComponent* GetLifeStatsComponent() const { return LifeStatsComp; }

};

