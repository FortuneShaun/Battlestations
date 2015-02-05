// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "EnemyAI_Boat.h"
#include "Public/Grid/EmptyGridElement.h"
#include "BattleshipBoardPawn.h"
#include "Public/Grid/PlayerGrid_Empty.h"
#include "Public/Grid/PlayerGrid_Ship.h"
#include "EnemyGrid_Hidden.h"

AEnemyAI_Boat::AEnemyAI_Boat(const FObjectInitializer& PCIP) : Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	//AIEmpty = this;
}

void AEnemyAI_Boat::Tick(float DeltaSeconds)
{
	ABattleshipBoardPawn* Char = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!Char->bIsTurn && Char->bIsPlaying)
	{
		Attack();
	}
}

void AEnemyAI_Boat::Attack()
{
	ABattleshipBoardPawn* Char = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerBoats.Num() > 0)
	{
		int32 PlayerShipToAttack = FMath::RandRange(0, PlayerBoats.Num() - 1);
		
		Char->PlayerShips.Remove((APlayerGrid_Ship*)PlayerBoats[PlayerShipToAttack]);
		PlayerBoats[PlayerShipToAttack]->Destroy();
		PlayerBoats.RemoveAt(PlayerShipToAttack, 1, true);

		Char->bIsTurn = true;
	}

	if (Char->EnemyShips.Num() == 0 || Char->PlayerShips.Num() == 0)
	{
		Char->bIsTurn = false;
		Char->TimeToFire = 6000000;
	}
}

void AEnemyAI_Boat::BeginPlay()
{
	SetupEnemyBoats();
}

void AEnemyAI_Boat::SetupEnemyBoats()
{
	int32 EnemyShipsCreated = 0;

	ABattleshipBoardPawn* Char = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();

	while (EnemyShipsCreated != 10)
	{
		for (int32 i = 0; i < EnemyBoats.Num(); i++)
		{
			int32 IsArmed = FMath::RandRange(0, 1);
			AEnemyGrid_Hidden* EnemyShip = (AEnemyGrid_Hidden*)EnemyBoats[i];
			if (EnemyShipsCreated < 10 && !EnemyShip->bHasShip)
			{
				switch (IsArmed)
				{
				case 0:
					break;
				case 1:
					EnemyShip->bHasShip = true;
					EnemyShipsCreated++;
					Char->EnemyShips.Add(EnemyShip);
					break;
				}
			}
		}
	}
	ABattleshipBoardPawn* const Player = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();
	Player->ShipsRemainingToPlace = EnemyShipsCreated;
}
