// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Grid/GridElement.h"
#include "GridElementEmpty_Player.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESTATIONS_API AGridElementEmpty_Player : public AGridElement
{
	GENERATED_BODY()
public:
	//Class constructor
	AGridElementEmpty_Player(const FObjectInitializer& PCIP);
};
