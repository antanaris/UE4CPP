#pragma once

UENUM(BlueprintType)
enum EInventoryItemType
{
	Default	UMETA(DisplayName = "Default"),
	Sphere    UMETA(DisplayName = "Sphere"),
	Cube    UMETA(DisplayName = "Cube"),
	Cylinder UMETA(DisplayName = "Cylinder")
};
