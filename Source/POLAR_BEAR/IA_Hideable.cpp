// Fill out your copyright notice in the Description page of Project Settings.


#include "IA_Hideable.h"


void IIA_Hideable::Hide()
{
	UE_LOG(LogTemp, Warning, TEXT("IIA_Hideable::Hide"));
}

// Add default functionality here for any IIA_Hideable functions that are not pure virtual.
void IIA_Hideable::Unhide()
{
	UE_LOG(LogTemp, Warning, TEXT("IIA_Hideable::UnHide"));
}
