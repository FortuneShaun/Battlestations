// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "PlayerGrid_Ship.h"
#include "PlayerGrid_Empty.h"
#include "Public/Pawn/BattleshipBoardPawn.h"

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

		Player->ShipsRemainingToPlace--;
		World->SpawnActor<APlayerGrid_Ship>(APlayerGrid_Ship::StaticClass(), GetActorLocation(), GetActorRotation());
		Destroy();
	}

	if (Player && Player->ShipsRemainingToPlace <= 0)
	{
		Player->bIsPlaying = true;
	}
}
