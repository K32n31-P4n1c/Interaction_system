// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "RadialImpulse.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_SYSTEM_API URadialImpulse : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URadialImpulse();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, Category="Forces")
	float Radius = 500.0f;
	UPROPERTY(EditANywhere, Category="Forces")
	float Strength = 2000.0f;
};
