// Fill out your copyright notice in the Description page of Project Settings.


#include "Sur/Interaction Actors/BaseInteractionActor.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/InputSettings.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Sur/SurCharacter.h"
#include "Sur/UI/InteractionWidget.h"

// Sets default values
ABaseInteractionActor::ABaseInteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComponent);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComp"));
	WidgetComponent->AttachTo(MeshComponent);
	WidgetComponent->SetRelativeLocation(FVector(0,0,80));
	WidgetComponent->SetVisibility(false);
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
}

// Called when the game starts or when spawned
void ABaseInteractionActor::BeginPlay()
{
	Super::BeginPlay();
   
	InteractWidget = Cast<UInteractionWidget>(WidgetComponent->GetUserWidgetObject());
	SurChar = Cast<ASurCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));    
}

// Called every frame
void ABaseInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseInteractionActor::OnBecameActive()
{
    if (WidgetComponent)
    {
		WidgetComponent->SetVisibility(true);
    }
}

void ABaseInteractionActor::OnStoppedActive()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetVisibility(false);
	}
}

