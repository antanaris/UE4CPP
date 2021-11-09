// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorComponent.h"


// Sets default values for this component's properties
UInventoryActorComponent::UInventoryActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryActorComponent::SetSize(const FIntVector& NewSize)
{
	Inventory.Size = NewSize;
	Inventory.SlotsOccupied = Inventory.Items.Num();
	Inventory.SlotsFree = Inventory.Size.X * Inventory.Size.Y * Inventory.Size.Z - Inventory.SlotsOccupied;
}

void UInventoryActorComponent::AddItem(const FInventoryItem& Item, bool& Result)
{
	if (Inventory.SlotsFree > 0)
    {
		Inventory.Items.Add(Item);
		Inventory.SlotsOccupied++;
		Inventory.SlotsFree--;
		Result = true;
    }
    else
    {
        Result = false;
    }
	
}

void UInventoryActorComponent::RemoveItem(const FInventoryItem& Item)
{
	Inventory.Items.Remove(Item);
	Inventory.SlotsOccupied--;
	Inventory.SlotsFree++;
}

void UInventoryActorComponent::SetDefaultInventory(const FInventory& DefaultInventory)
{
	Inventory = DefaultInventory;
}

