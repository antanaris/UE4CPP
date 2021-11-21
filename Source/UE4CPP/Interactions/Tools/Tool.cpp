// Fill out your copyright notice in the Description page of Project Settings.


#include "Tool.h"

// Sets default values
ATool::ATool()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create Root Component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create the box collision component
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);
	
	// Create the weapon mesh component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(CollisionBox);
}

// Called when the game starts or when spawned
void ATool::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
