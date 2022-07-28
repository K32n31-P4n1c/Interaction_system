// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "ApplyImpulse.h"
#include "CollisionQueryParams.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UApplyImpulse::UApplyImpulse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called every frame
void UApplyImpulse::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult Hit;

	const FVector Start = GetComponentLocation();
	FVector End = Start + GetComponentRotation().Vector() * TraceDistance;

	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(GetOwner());
	
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit,Start, End, ECC_Visibility, TraceParams);

	if (bHit)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Magenta, false, 0.1f);

		UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(Hit.GetActor()->GetRootComponent());
		
		if (MeshComponent && Hit.GetActor()->IsRootComponentMovable())
		{
			
			FVector Forward = this->GetForwardVector();
			MeshComponent->AddImpulse(Forward * ImpulseForce * MeshComponent->GetMass());
		}
	}
}

