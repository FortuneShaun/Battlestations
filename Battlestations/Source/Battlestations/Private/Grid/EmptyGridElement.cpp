// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "EmptyGridElement.h"

AEmptyGridElement::AEmptyGridElement(const FObjectInitializer& PCIP) : Super(PCIP)
{
	GridMesh = PCIP.CreateDefaultSubobject <UStaticMeshComponent> (this, "Grid Tile");
	RootComponent = GridMesh;

	UStaticMesh* GridAsset = GetAsset<UStaticMesh> (TEXT("StaticMesh'/Game/GridElement_Player.GridElement_Player'"));

	GridMesh->SetStaticMesh(GridAsset);

	this->SetActorScale3D(FVector(.5, .5, .5));
}
