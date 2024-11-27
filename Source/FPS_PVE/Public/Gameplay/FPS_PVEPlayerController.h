// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Character/FPS_PVEPlayer.h>
#include "FPS_PVEPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PVE_API AFPS_PVEPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// 控制玩家
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVEPlayerController")
	ACharacter* ControlledPlayer = nullptr;

	// Z轴晃动量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVEPlayerController")
	float Z_AxisOscillation = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVEPlayerController")
	TSubclassOf<UUserWidget> AimStar = nullptr;
	
};
