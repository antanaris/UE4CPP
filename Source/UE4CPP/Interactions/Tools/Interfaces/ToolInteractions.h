// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE4CPP/Interactions/Tools/Tool.h"
#include "UObject/Interface.h"
#include "ToolInteractions.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UToolInteractions : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE4CPP_API IToolInteractions
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Take tool in hand
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Tool Interactions")
	void TakeInHand(ATool* Tool);

	// Put tool down
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Tool Interactions")
	void PutDown();
};
