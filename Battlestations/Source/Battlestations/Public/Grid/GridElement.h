// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GridElement.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESTATIONS_API AGridElement : public AActor
{
	GENERATED_BODY()
public:
	//Class constructor
	AGridElement(const FObjectInitializer& PCIP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	//The mesh for this grid element
	UStaticMeshComponent* GridElementMesh;
};
