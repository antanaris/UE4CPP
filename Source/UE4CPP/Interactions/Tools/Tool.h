// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Tool.generated.h"

class ATool;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnToolBeginOverlap);


UCLASS()
class UE4CPP_API ATool : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATool();

	// Static Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* CollisionBox;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Parameters

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tool")
	bool bIsDebug = false;

	// Dynamic Multicast Delegates (shows as Event Dispatcher in Blueprints)
	UPROPERTY(BlueprintAssignable, Category = "Tool")
	FOnToolBeginOverlap OnToolBeginOverlap;

};
