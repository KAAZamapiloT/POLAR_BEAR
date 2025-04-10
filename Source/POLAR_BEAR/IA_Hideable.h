﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IA_Hideable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UIA_Hideable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class POLAR_BEAR_API IIA_Hideable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void Hide();
	virtual void Unhide();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetActive();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetHidden();
};
