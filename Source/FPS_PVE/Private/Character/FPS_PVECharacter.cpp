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

	// �������ֵС�ڵ���0��������δ����
	if (Health <= 0.0f && !bHasDied)
	{
		// ִ�������߼�
		OnDeath();
	}

	return ActualDamage;
}

void AFPS_PVECharacter::OnDeath()
{
	bHasDied = true; // ȷ�������߼�ִֻ��һ��

	// ��ȡ��ǰ��ҿ�����
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		// ��������
		PlayerController->DisableInput(PlayerController);
	}

	// ��ȡMesh�������������ģ��
	if (UPrimitiveComponent* MeshComponent = Cast<UPrimitiveComponent>(GetComponentByClass(UPrimitiveComponent::StaticClass())))
	{
		MeshComponent->SetSimulatePhysics(true);
	}

	// ����һ��6����ӳ٣�֮������Actor
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

