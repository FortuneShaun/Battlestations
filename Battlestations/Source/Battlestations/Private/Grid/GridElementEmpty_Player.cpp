// Fill out your copyright notice in the Description page of Project Settings.

#include "Battlestations.h"
#include "GridElementEmpty_Player.h"

AGridElementEmpty_Player::AGridElementEmpty_Player(const FObjectInitializer& PCIP) : Super(PCIP)
{
	UStaticMesh* PlayerMesh = getAsset <UStaticMesh>(TEXT("StaticMesh'/Game/GridElement_Player.GridElement_Player'"));

	GridElementMesh->SetStaticMesh(PlayerMesh);
}
