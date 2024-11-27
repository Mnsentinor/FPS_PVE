// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/FPS_PVECharacter.h"
#include "FPS_PVEPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PVE_API AFPS_PVEPlayer : public AFPS_PVECharacter
{
	GENERATED_BODY()

public:
	AFPS_PVEPlayer();
	
public:
	// 设置玩家输入的绑定
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//// 射击按键按下时的处理函数
	//void Shoot();

	//// 射击按键松开时的处理函数
	//void StopShoot();

protected:
	// 武器威力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVEPlayer")
	float WeaponPower = 34;
};
