// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemyAI_Boat.generated.h"

class AEmptyGridElement;

/**
 * 
 */
UCLASS()
class BATTLESTATIONS_API AEnemyAI_Boat : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boats")
	//Player boats
	TArray<AEmptyGridElement*> PlayerBoats; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boats")
	//Enemy boats
	TArray<AEmptyGridElement*> EnemyBoats;

	//Class constructor
	AEnemyAI_Boat(const FObjectInitializer& PCIP);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void Attack();

	void SetupEnemyBoats();
};
