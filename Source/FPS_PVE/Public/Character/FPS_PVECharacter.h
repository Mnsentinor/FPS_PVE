// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPS_PVECharacter.generated.h"

UCLASS()
class FPS_PVE_API AFPS_PVECharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPS_PVECharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// �ܵ��˺�
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	// ���������߼�
	void OnDeath();

	// �ӳ����ٵĺ���
	void DestroyActorFunction();

	//// �����������ʱ�Ĵ�����
	//UPROPERTY(BlueprintCallable, Category = "FPS_PVECharacter")
	//void Shoot();

	//// ��������ɿ�ʱ�Ĵ�����
	//UPROPERTY(BlueprintCallable, Category = "FPS_PVECharacter")
	//void StopShoot();

protected:
	// ����ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVECharacter")
	float Health = 100.0f;

	// �Ƿ�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVECharacter")
	bool bHasDied = false;

	// ȷ�������߼�ִֻ��һ�εı�־
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVECharacter")
	bool IsFire = false;

	// ��ʱ������������ӳ�����
	FTimerHandle DestroyTimerHandle;

};
