#pragma once

#include "Blueprint/BlueprintSupport.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "../Structs/InventoryItem.h"
#include "InventoryItemInfo.generated.h"

UINTERFACE(Blueprintable)
class UInventoryItemInfo : public UInterface
{
	GENERATED_BODY()

};

class IInventoryItemInfo
{
public:

	GENERATED_BODY()

	// Getter. Returns value to InventoryItem variable
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Inventory Item")
	void GetInventoryItem(FInventoryItem& InventoryItem);
	void GetInventoryItem_Implementation(FInventoryItem& InventoryItem);
	

	// Setter. Using UPARAM(ref) to pass value or mark it as const
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Inventory Item")
	void SetID(const int32& ID);
	
};
