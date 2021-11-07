#include "InventoryItemBPI.h"

void IInventoryItemBPI::GetInventoryItem_Implementation(FInventoryItem& InventoryItem)
{
    InventoryItem = FInventoryItem(0, InventoryItemType::Default, FIntVector(1,1,1), "Name", "");
}
