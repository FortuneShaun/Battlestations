// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "EnemyGrid_Hidden.h"
#include "BattleshipBoardPawn.h"





void AEnemyGrid_Hidden::OnClickedGrid(UPrimitiveComponent* Comp)
{
	ABattleshipBoardPawn* const Player = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();

	if (Player && Player->bIsPlaying && Player->bIsTurn)
	{
		Player->bIsTurn = false;

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
