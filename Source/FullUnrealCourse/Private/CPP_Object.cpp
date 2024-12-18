// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Object.h"

void UCPP_Object::Test(UPARAM(ref)FBook& Target)
{
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Purple, TEXT("Test"));
}
