// Fill out your copyright notice in the Description page of Project Settings.


#include "AddForce.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UAddForce::UAddForce()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAddForce::BeginPlay()
{
	Super::BeginPlay();

	MeshComp = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
}


// Called every frame
void UAddForce::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector Up = this->GetUpVector();

	MeshComp->AddForce(Up * Force * MeshComp->GetMass());
}

