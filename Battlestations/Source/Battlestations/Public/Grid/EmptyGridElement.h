// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EmptyGridElement.generated.h"

/**
 * Base class for all grid tiles
 */
UCLASS()
class BATTLESTATIONS_API AEmptyGridElement : public AActor
{
	GENERATED_BODY()
public:
	//Class constructor
	AEmptyGridElement(const FObjectInitializer& PCIP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiles")
	//The tile of the grid element
	UStaticMeshComponent* GridMesh;
	
	UPROPERTY(BlueprintReadWrite, Category = "Tile Info")
	//Whether the tile has been shot
	bool bIsDead;
};
