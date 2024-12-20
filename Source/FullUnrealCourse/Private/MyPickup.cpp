// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPickup.h"

// Sets default values
AMyPickup::AMyPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SomeVariable = 10;
}

// Called when the game starts or when spawned
void AMyPickup::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Purple, FString::FromInt(SomeVariable));
}

// Called every frame
void AMyPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPickup::Destruct()
{
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Purple, TEXT("Destroyed Form C++"));
	Destroy();
}

