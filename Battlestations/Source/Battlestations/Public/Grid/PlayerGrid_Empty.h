// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Grid/EmptyGridElement.h"
#include "PlayerGrid_Empty.generated.h"

class AEnemyAI_Boat;

/**
 * 
 */
UCLASS()
class BATTLESTATIONS_API APlayerGrid_Empty : public AEmptyGridElement
{
	GENERATED_BODY()
public:
	//Class constructor
	APlayerGrid_Empty(const FObjectInitializer& PCIP);

	UFUNCTION()
	//For when the player clicks the grid
	void OnClickedGrid(UPrimitiveComponent* Comp);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	AEnemyAI_Boat* ShipAI;
};