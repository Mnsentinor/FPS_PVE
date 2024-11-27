// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPS_PVEPlayer.h"

AFPS_PVEPlayer::AFPS_PVEPlayer()
{

}

void AFPS_PVEPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //// 绑定InputAction "Shoot" 到 Shoot 和 StopShoot 函数
    //PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AFPS_PVEPlayer::Shoot);
    //PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AFPS_PVEPlayer::StopShoot);
}

//void AFPS_PVEPlayer::Shoot()
//{
//}
//
//void AFPS_PVEPlayer::StopShoot()
//{
//}
