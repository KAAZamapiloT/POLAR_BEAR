// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IA_intractable.generated.h"

// This class does not need to be modified.
// Interface added to put actors which are intractable in one category
// Added to make interaction easier -> lights on/off , door open/close etc
UINTERFACE()
class UIA_intractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class POLAR_BEAR_API IIA_intractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void signal(){}
};
