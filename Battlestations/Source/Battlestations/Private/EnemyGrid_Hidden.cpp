// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "EnemyGrid_Hidden.h"
#include "BattleshipBoardPawn.h"





void AEnemyGrid_Hidden::OnClickedGrid(UPrimitiveComponent* Comp)
{
	ABattleshipBoardPawn* const Player = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();

	//If the player is playing, its their turn and they can fire
	if (Player && Player->bIsPlaying && Player->bIsTurn && Player->bCanFire && !bIsDead)
	{
		Player->bIsTurn = false;
		Player->TimeToFire = 3;
		Player->bCanFire = false;
		bIsDead = true;

		if (bHasShip)
		{
			Destroy();
		}
		else
		{

		}
	}
}

AEnemyGrid_Hidden::AEnemyGrid_Hidden(const FObjectInitializer& PCIP) : Super(PCIP)
{
	GridMesh->OnClicked.AddDynamic(this, &AEnemyGrid_Hidden::OnClickedGrid);
	GridMesh->SetStaticMesh(GetAsset<UStaticMesh>(TEXT("StaticMesh'/Game/GridElement_Enemy.GridElement_Enemy'")));
}
