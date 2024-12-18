// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPP_Object.generated.h"

UENUM(BlueprintType)
enum FruitList
{
	Apple,
	Mange,
	Bannana,
};

USTRUCT(BlueprintType)
struct FBook
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Pages;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Rating;
};

/**
 * 
 */
UCLASS(Blueprintable)
class FULLUNREALCOURSE_API UCPP_Object : public UObject
{
	GENERATED_BODY()
	
private:
	int OurInt;

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int OurPubInt;

	UFUNCTION(BlueprintPure)
	int GetOurInt() { return OurInt; }

	UFUNCTION(BlueprintCallable)
	void SetOurInt(int NewInt) { OurInt = NewInt; }

	UFUNCTION(BlueprintCallable)
	static void Test(UPARAM(ref)FBook& Target);
};
