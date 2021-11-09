// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structs/InventoryItem.h"
#include "Structs/Inventory.h"
#include "InventoryActorComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE4CPP_API UInventoryActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryActorComponent();

	// Inventory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory")
	FInventory Inventory = FInventory();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	// Define the number and geometry of inventory slots
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetSize(const FIntVector& NewSize);

	// Add an item to the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(const FInventoryItem& Item, bool& Result);

	// Remove an item from the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(const FInventoryItem& Item);

	// Set default inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetDefaultInventory(const FInventory& DefaultInventory);
};
