// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"
#include "Sur/SurCharacter.h"
#include "EngineUtils.h"
#include "Particles/ParticleSystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Sur/Interfaces/InteractionInterface.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ASurCharacter>(GetOwner());
	CosInteractionAngle = FMath::Cos(FMath::DegreesToRadians(InteractionAngle));
	// ...
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (OwnerCharacter)
	{
		IInteractionInterface* NearestActor = nullptr;
		for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (IInteractionInterface* UsableActor = Cast<IInteractionInterface>(*ActorItr))
			{
			    const float CosAngle = FMath::Abs(FVector::DotProduct(OwnerCharacter->GetFollowCamera()->GetForwardVector().GetSafeNormal(),
					(OwnerCharacter->GetFollowCamera()->GetComponentLocation() - ActorItr->GetActorLocation()).GetSafeNormal()));

				if (OwnerCharacter->GetDistanceTo(*ActorItr) <= InteractionDistance && CosAngle >= CosInteractionAngle)
				{
					float CosAngleToNearestActor = 0.0f;
					if (!NearestActor || FMath::Abs(FVector::DotProduct(OwnerCharacter->GetFollowCamera()->GetForwardVector().GetSafeNormal(),
						(OwnerCharacter->GetFollowCamera()->GetComponentLocation() - NearestActor->GetOwningActor()->GetActorLocation()).GetSafeNormal())) < CosAngle)
					{
						NearestActor = UsableActor;
					}
				}
				
			}
		}
        if (NearestActor && NearestActor->GetOwningActor())
        {
			UE_LOG(LogTemp, Error, TEXT("Name: %s"), *NearestActor->GetOwningActor()->GetName());
        }
	}

	// ...
}

