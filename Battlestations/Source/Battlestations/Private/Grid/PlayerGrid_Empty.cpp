// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "PlayerGrid_Ship.h"
#include "PlayerGrid_Empty.h"
#include "Public/Pawn/BattleshipBoardPawn.h"
#include "Public/EnemyAI_Boat.h"

APlayerGrid_Empty::APlayerGrid_Empty(const FObjectInitializer& PCIP) : Super(PCIP)
{
	GridMesh->OnClicked.AddDynamic(this, &APlayerGrid_Empty::OnClickedGrid);
}

void APlayerGrid_Empty::OnClickedGrid(UPrimitiveComponent* Comp)
{
	ABattleshipBoardPawn* const Player = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();

	if (Player && !Player->bIsPlaying && Player->ShipsRemainingToPlace > 0)
	{
		UWorld* const World = GetWorld();

		for (int32 i = 0; i < ShipAI->PlayerBoats.Num(); i++)
		{
			if (ShipAI->PlayerBoats[i] == this)
			{
				Player->ShipsRemainingToPlace--;
				ShipAI->PlayerBoats[i] = World->SpawnActor<APlayerGrid_Ship>(APlayerGrid_Ship::StaticClass(), GetActorLocation(), GetActorRotation());
				APlayerGrid_Ship* a = (APlayerGrid_Ship*)ShipAI->PlayerBoats[i];
				a->ShipAI = ShipAI;
				Destroy();
			}
		}
	}

	if (Player && Player->ShipsRemainingToPlace <= 0)
	{
		Player->bIsPlaying = true;
	}
}
