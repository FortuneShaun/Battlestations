// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "BattleshipBoardPawn.generated.h"

class APlayerGrid_Ship;
class AEnemyGrid_Hidden;

/**
 * Character that holds the players ships and whether its their turn or not
 */
UCLASS()
class BATTLESTATIONS_API ABattleshipBoardPawn : public APawn
{
	GENERATED_BODY()
public:
	//Class constructor
	ABattleshipBoardPawn(const FObjectInitializer& PCIP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	//The camera that the pawn uses
	UCameraComponent* PawnCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player Input")
	//Whether its the player's turn or not
	bool bIsTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ships")
	//The amount of ships that need to be placed
	int32 ShipsRemainingToPlace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ships")
	//All the player ships
	TArray<APlayerGrid_Ship*> PlayerShips;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ships")
	//All the Enemy ships
	TArray<AEnemyGrid_Hidden*> EnemyShips;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placement")
	//Whether the player can place or remove ships
	bool bIsPlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placement")
	//Whether the player can fire at enemy ships
	bool bCanFire;

	float TimeToFire;

	virtual void Tick(float DeltaSeconds) override;
};
