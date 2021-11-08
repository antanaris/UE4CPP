// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActorComponentC.h"


// Sets default values for this component's properties
UInventoryActorComponentC::UInventoryActorComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryActorComponentC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryActorComponentC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryActorComponentC::SetSize(const FIntVector& NewSize)
{
	Inventory.Size = NewSize;
	Inventory.SlotsOccupied = Inventory.Items.Num();
	Inventory.SlotsFree = Inventory.Size.X * Inventory.Size.Y * Inventory.Size.Z - Inventory.SlotsOccupied;
}

void UInventoryActorComponentC::AddItem(const FInventoryItem& Item, bool& Result)
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

void UInventoryActorComponentC::RemoveItem(const FInventoryItem& Item)
{
	Inventory.Items.Remove(Item);
	Inventory.SlotsOccupied--;
	Inventory.SlotsFree++;
}

void UInventoryActorComponentC::SetDefaultInventory(const FInventory& DefaultInventory)
{
	Inventory = DefaultInventory;
}

