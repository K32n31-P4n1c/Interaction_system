// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AddForce.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTION_SYSTEM_API UAddForce : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAddForce();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category= "Forces")
	float Force = 1000.0f;

};
