// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/AudioComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OurIntArray = { 1,2,3,4,5 };

	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	OurIntArray.Reserve(6);
	OurIntArray.Add(12);
	OurIntArray.Emplace(45);
	OurIntArray.Remove(1);
	OurIntArray.RemoveAt(0);

	for (int i = 0; i < OurIntArray.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), OurIntArray[i]);
	}

	UWorld* World = GetWorld();

	if (ActorToSpawn && GetWorld())
	{
		FVector SpawnLocation = FVector(0, 0, 200);
		AActor* Pickup =  GetWorld()->SpawnActor<AMyPickup>(ActorToSpawn);
		Pickup->SetActorLocation(SpawnLocation);
	}
	
	if (!GIsServer)
	{
		TestServerRPC();
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::RemovePickup()
{
	CameraManager =  UGameplayStatics::GetPlayerCameraManager(this, 0);
	FVector ForwardVector = CameraManager->GetActorForwardVector() * 50000;
	FVector CameraLocation = CameraManager->GetCameraLocation();
	FVector EndLocation = CameraLocation + ForwardVector;

	TArray<AActor*> IgnoreActors;

	FHitResult Hit;
	UKismetSystemLibrary::LineTraceSingle(this, CameraLocation, EndLocation, ETraceTypeQuery::TraceTypeQuery1, 0, IgnoreActors, EDrawDebugTrace::ForDuration, Hit, true);

	UGameplayStatics::PlaySound2D(GetWorld(), Gunshot, 1, 1, 0, NULL, NULL, true);
	if (Hit.GetActor())
	{
		if (Cast<IMyInterface>(Hit.GetActor()))
		{
			IMyInterface* Interface = Cast<IMyInterface>(Hit.GetActor());
			Interface->Destruct();
		}
	}
}

void APlayerCharacter::TestBPNativeFunc_Implementation(float x)
{
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Purple, TEXT("C++ Implementation Called"));
}

// Replicated Variables

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APlayerCharacter, ReplicatedFloat);
}

void APlayerCharacter::TestServerRPC_Implementation()
{
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Purple, TEXT("This is a server RPC from c++"));
}
