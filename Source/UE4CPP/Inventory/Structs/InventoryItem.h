#pragma once

#include "../Enums/InventoryItemType.h"
#include "InventoryItem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory Item")
	int32 ID = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory Item")
	TEnumAsByte<EInventoryItemType> Type = EInventoryItemType::Default;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory Item")
	FIntVector Size = FIntVector(1, 1, 1);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory Item")
	FString Name = "Item";
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory Item")
	FString Description = "";

	// Constructors
	FInventoryItem() {};

FORCEINLINE	FInventoryItem(const int32 ID, const TEnumAsByte<EInventoryItemType>& Type, const FIntVector& Size, const FString& Name,
		const FString& Description)
		: ID(ID),
		  Type(Type),
		  Size(Size),
		  Name(Name),
		  Description(Description)
	{
	}

	// Equality operator (we ignore other fields, since when added to inventory unique IDs are used)
	FORCEINLINE bool operator==(const FInventoryItem& Other) const
    {
        return ID == Other.ID;
    }
};
