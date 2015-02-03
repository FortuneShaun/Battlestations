// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

template<class TypeName>
TypeName* GetAsset(TCHAR* AssetRef)
{
	ConstructorHelpers::FObjectFinder<TypeName> Asset(AssetRef);
	return Asset.Object;
}