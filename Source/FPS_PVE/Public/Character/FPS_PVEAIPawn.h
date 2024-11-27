// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/FPS_PVECharacter.h"
#include "FPS_PVEAIPawn.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PVE_API AFPS_PVEAIPawn : public AFPS_PVECharacter
{
	GENERATED_BODY()

protected:
	// ÊÇ·ñ×·×Ù
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVEAIPawn")
	bool IsTrackEnemy = false;
};
