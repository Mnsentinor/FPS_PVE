// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPS_PVECharacter.h"

// Sets default values
AFPS_PVECharacter::AFPS_PVECharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_PVECharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_PVECharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPS_PVECharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AFPS_PVECharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	Health -= ActualDamage;

	// 如果生命值小于等于0，并且尚未死亡
	if (Health <= 0.0f && !bHasDied)
	{
		// 执行死亡逻辑
		OnDeath();
	}

	return ActualDamage;
}

void AFPS_PVECharacter::OnDeath()
{
	bHasDied = true; // 确保死亡逻辑只执行一次

	// 获取当前玩家控制器
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		// 禁用输入
		PlayerController->DisableInput(PlayerController);
	}

	// 获取Mesh组件并启用物理模拟
	if (UPrimitiveComponent* MeshComponent = Cast<UPrimitiveComponent>(GetComponentByClass(UPrimitiveComponent::StaticClass())))
	{
		MeshComponent->SetSimulatePhysics(true);
	}

	// 设置一个6秒的延迟，之后销毁Actor
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AFPS_PVECharacter::DestroyActorFunction, 6.0f, false);
}

void AFPS_PVECharacter::DestroyActorFunction()
{
	Destroy();
}

//void AFPS_PVECharacter::Shoot()
//{
//}
//
//void AFPS_PVECharacter::StopShoot()
//{
//}

