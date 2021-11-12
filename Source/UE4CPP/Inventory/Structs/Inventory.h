#pragma once

#include "InventoryItem.h"
//#include "UE4CPP/Enums/InventoryItemType.h"
#include "Inventory.generated.h"

USTRUCT(BlueprintType)
struct FInventory
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	FString Name = "Inventory";
	
	// 1, 2 or 3d inventory slots arrangement. Works like 2x2 --> 4 slots --> FIntVector(2,2,1). Leave 1 for reducing dimentionality.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	FIntVector Size = FIntVector(1, 1, 1);

	// Inventory items
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	TArray<FInventoryItem> Items;

	// Read only properties
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory")
	int32 SlotsOccupied = 0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory")
	int32 SlotsFree = Size.X * Size.Y * Size.Z;;

	// Slot types (from InventoryItemType)
	// Add ability to assign types to slots

	
	// Constructors
	FInventory() {};

	FInventory(const FIntVector& Size) : Size(Size)
    {
        Items = TArray<FInventoryItem>();
        SlotsOccupied = 0;
        SlotsFree = Size.X * Size.Y * Size.Z;
    }

	FInventory(const FString Name, const FIntVector& Size) : Name(Name), Size(Size)
	{
		Items = TArray<FInventoryItem>();
		SlotsOccupied = 0;
		SlotsFree = Size.X * Size.Y * Size.Z;
	}

	FInventory(const FString Name, const FIntVector& Size, const TArray<FInventoryItem>& NewItems) : Name(Name), Size(Size), Items(NewItems)
	{
		// ToDo: Take into account item size
		if (Items.Num() > Size.X * Size.Y * Size.Z)
		{
			Items.SetNum(Size.X * Size.Y * Size.Z);
		}
			SlotsOccupied = Items.Num();
			SlotsFree = Size.X * Size.Y * Size.Z - SlotsOccupied;
	}

	//void AddItem(const FInventoryItem& Item);
};