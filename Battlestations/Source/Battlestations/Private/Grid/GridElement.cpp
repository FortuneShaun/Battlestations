// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "GridElement.h"

AGridElement::AGridElement(const FObjectInitializer& PCIP) : Super(PCIP)
{
	GridElementMesh = PCIP.CreateDefaultSubobject <UStaticMeshComponent> (this, "Grid Element");
	RootComponent = GridElementMesh;
}
