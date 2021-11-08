// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Structs/Inventory.h"
#include "MainPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UE4CPP_API AMainPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory")
	FInventory PlayerInventory;
	
	/* Default inventory moved to BP
	FInventory("Player Inventory", FIntVector(2, 3, 1),
		[	FInventoryItem(1, InventoryItemType::Cube, FIntVector(1, 1, 1), "Cube", "Default Cube Inventory Item"),
			FInventoryItem(2, InventoryItemType::Sphere, FIntVector(1, 1, 1), "Sphere", "Default Sphere Inventory Item"),
			FInventoryItem(3, InventoryItemType::Cylinder, FIntVector(1, 1, 1), "Cylinder", "Default Cylinder Inventory Item")]);
			*/
	
};
