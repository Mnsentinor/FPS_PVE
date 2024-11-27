// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FPS_PVEAIController.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PVE_API AFPS_PVEAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// ¿ØÖÆ Pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AFPS_PVEAIController")
	APawn* ControlledPawn = nullptr;
	
};
