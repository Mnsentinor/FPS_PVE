// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPS_PVEPlayer.h"

AFPS_PVEPlayer::AFPS_PVEPlayer()
{

}

void AFPS_PVEPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //// ��InputAction "Shoot" �� Shoot �� StopShoot ����
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
