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
	// �����������İ�
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//// �����������ʱ�Ĵ�����
	//void Shoot();

	//// ��������ɿ�ʱ�Ĵ�����
	//void StopShoot();

protected:
	// ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVEPlayer")
	float WeaponPower = 34;
};
