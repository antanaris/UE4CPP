#include "InventoryItemInfo.h"

void IInventoryItemInfo::GetInventoryItem_Implementation(FInventoryItem& InventoryItem)
{
    InventoryItem = FInventoryItem(0, EInventoryItemType::Default, FIntVector(1,1,1), "Name", "");
}
