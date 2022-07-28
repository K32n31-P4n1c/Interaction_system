// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialInstanceDynamicChange.h"

// Sets default values
AMaterialInstanceDynamicChange::AMaterialInstanceDynamicChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void AMaterialInstanceDynamicChange::BeginPlay()
{
	Super::BeginPlay();
	
	// Get the Material in the first slot
	// ** NOTE ** Needs to be a Material Instance. Base Materialls will not work.
	Material = Mesh->GetMaterial(0);

	// Make a new Dynamic Material Instance from the Material sotred above. This is why we needed a Material Instance.
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);

	//Set the Material slot 1 to be our Dynamic version. This allows runtime changes.
	Mesh->SetMaterial(0,DynamicMaterial);

	//Set the parameters for the Dynamic Material Instace, these will be the names inside of the Material/Material Instance.
	DynamicMaterial->SetScalarParameterValue(TEXT("EmissiveStrength"), 50);
	DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FLinearColor::Yellow);
}

// Called every frame
void AMaterialInstanceDynamicChange::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

