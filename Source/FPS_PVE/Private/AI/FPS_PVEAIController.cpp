// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/FPS_PVEAIController.h"
#include <Kismet/GameplayStatics.h>

void AFPS_PVEAIController::BeginPlay()
{
	Super::BeginPlay();

	// ��ȡ��ǰ AI ���ƵĽ�ɫ 
	ControlledPawn = GetPawn();
}
