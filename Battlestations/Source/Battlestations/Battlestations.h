// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

template<class TypeName>
TypeName* getAsset(TCHAR* tChar)
{
	ConstructorHelpers::FObjectFinder<TypeName> obj(tChar);
	return obj.Object;
}