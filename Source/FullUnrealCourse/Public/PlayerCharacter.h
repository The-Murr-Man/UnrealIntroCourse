// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyPickup.h"
#include "Net/UnrealNetwork.h"
#include "PlayerCharacter.generated.h"

class USoundBase;

UCLASS()
class FULLUNREALCOURSE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	APlayerCameraManager* CameraManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void RemovePickup();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void TestBPFunc(int x);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TestBPNativeFunc(float x);

	void TestBPNativeFunc_Implementation(float x);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> OurIntArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, float> OurMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AMyPickup> ActorToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* Gunshot;

	UPROPERTY(BlueprintReadWrite, Replicated)
	float ReplicatedFloat;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable)
	void TestServerRPC();

	void TestServerRPC_Implementation();

};
