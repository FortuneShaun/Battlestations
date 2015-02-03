// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "PlayerGrid_Ship.h"
#include "PlayerGrid_Empty.h"
#include "Public/Pawn/BattleshipBoardPawn.h"

APlayerGrid_Ship::APlayerGrid_Ship(const FObjectInitializer& PCIP) : Super(PCIP)
{
	ShipMesh = PCIP.CreateDefaultSubobject <UStaticMeshComponent> (this, "Ship Mesh");
	ShipMesh->AttachParent = GridMesh;
	ShipMesh->RelativeLocation = FVector(0, 0, 175);
	ShipMesh->RelativeScale3D = FVector(.25, .25, .25);

	UStaticMesh* Ship = GetAsset<UStaticMesh>(TEXT("StaticMesh'/Game/Boat_ND.Boat_ND'"));

	ShipMesh->SetStaticMesh(Ship);

	GridMesh->OnClicked.AddDynamic(this, &APlayerGrid_Ship::OnClickedGrid);
	ShipMesh->OnClicked.AddDynamic(this, &APlayerGrid_Ship::OnClickedGrid);
}

void APlayerGrid_Ship::OnClickedGrid(UPrimitiveComponent* Comp)
{
	ABattleshipBoardPawn* const Player = (ABattleshipBoardPawn*)GetWorld()->GetFirstPlayerController()->GetPawn();

	if (Player && !Player->bIsPlaying && Player->ShipsRemainingToPlace > 0)
	{
		UWorld* const World = GetWorld();

		Player->ShipsRemainingToPlace++;
		World->SpawnActor<APlayerGrid_Empty>(APlayerGrid_Empty::StaticClass(), GetActorLocation(), GetActorRotation());
		Destroy();
	}

	if (Player && Player->ShipsRemainingToPlace <= 0)
	{
		Player->bIsPlaying = true;
	}
}
