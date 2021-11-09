// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/InventoryItem.h"
#include "InventoryItemObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew)
class UE4CPP_API UInventoryItemObject : public UObject
{
	GENERATED_BODY()

public:
//    UInventoryItemObject();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Item", meta = (ExposeOnSpawn="true"))
	FInventoryItem InventoryItem;
};
