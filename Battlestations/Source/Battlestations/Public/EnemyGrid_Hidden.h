// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Grid/EmptyGridElement.h"
#include "EnemyGrid_Hidden.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESTATIONS_API AEnemyGrid_Hidden : public AEmptyGridElement
{
	GENERATED_BODY()
public:
	AEnemyGrid_Hidden(const FObjectInitializer& PCIP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ships")
	//Whether the tile has ship
	bool bHasShip;

	UFUNCTION()
	//When the element has been clicked
	void OnClickedGrid(UPrimitiveComponent* Comp);
};
