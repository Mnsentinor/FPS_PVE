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

	// 受到伤害
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	// 死亡处理逻辑
	void OnDeath();

	// 延迟销毁的函数
	void DestroyActorFunction();

	//// 射击按键按下时的处理函数
	//UPROPERTY(BlueprintCallable, Category = "FPS_PVECharacter")
	//void Shoot();

	//// 射击按键松开时的处理函数
	//UPROPERTY(BlueprintCallable, Category = "FPS_PVECharacter")
	//void StopShoot();

protected:
	// 生命值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVECharacter")
	float Health = 100.0f;

	// 是否死亡
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVECharacter")
	bool bHasDied = false;

	// 确保死亡逻辑只执行一次的标志
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS_PVECharacter")
	bool IsFire = false;

	// 定时器句柄，用于延迟销毁
	FTimerHandle DestroyTimerHandle;

};
