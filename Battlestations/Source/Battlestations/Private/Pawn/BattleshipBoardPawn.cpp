// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "BattleshipBoardPawn.h"

ABattleshipBoardPawn::ABattleshipBoardPawn(const FObjectInitializer& PCIP) : Super(PCIP)
{
	PawnCamera = PCIP.CreateDefaultSubobject <UCameraComponent>(this, "Pawn Camera");
	PawnCamera->AttachParent = RootComponent;
	PawnCamera->RelativeLocation = FVector(0, 0, 1000);
	PawnCamera->RelativeRotation = FRotator(-90, 0, 0);

	bIsTurn = true;

	ShipsRemainingToPlace = 10;
	PrimaryActorTick.bCanEverTick = true;
}

void ABattleshipBoardPawn::Tick(float DeltaSeconds)
{
	if (bIsTurn && !bCanFire)
	{
		TimeToFire -= DeltaSeconds;

		if (TimeToFire <= 0)
		{
			bCanFire = true;
		}
	}
}
