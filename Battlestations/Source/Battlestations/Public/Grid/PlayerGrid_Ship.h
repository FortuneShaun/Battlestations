// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Grid/EmptyGridElement.h"
#include "PlayerGrid_Ship.generated.h"

class AEnemyAI_Boat;

/**
 * 
 */
UCLASS()
class BATTLESTATIONS_API APlayerGrid_Ship : public AEmptyGridElement
{
	GENERATED_BODY()
public:
	//Class constructor
	APlayerGrid_Ship(const FObjectInitializer& PCIP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
	//The mesh of the ship
	UStaticMeshComponent* ShipMesh;

	UFUNCTION()
	//When the player clicks the grid
	void OnClickedGrid(UPrimitiveComponent* Comp);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	AEnemyAI_Boat* ShipAI;
};