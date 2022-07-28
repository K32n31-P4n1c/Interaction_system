// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ApplyImpulse.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_SYSTEM_API UApplyImpulse : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UApplyImpulse();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere, Category="Force Variables")
	float TraceDistance = 1000.0f;
	UPROPERTY(EditAnywhere, Category="Force Variables")
	float ImpulseForce = 50.0f;

	
};
