// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/FPS_PVEPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h" 

void AFPS_PVEPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 获取当前玩家控制的角色 
	ControlledPlayer = UGameplayStatics::GetPlayerCharacter(this, 0);
	
	// 加载准星控件蓝图 
	// 运行时动态加载 Widget Blueprint
	AimStar = LoadClass<UUserWidget>(nullptr, TEXT("/Game/UI/PlayerGameUI.PlayerGameUI_C"));
	//AimStar = StaticLoadClass(UUserWidget::StaticClass(), nullptr, TEXT("WidgetBlueprint'/Game/UI/PlayerGameUI.PlayerGameUI_C'"));

	if (AimStar)
	{
		UUserWidget* AimStarWidget = CreateWidget<UUserWidget>(GetWorld(), AimStar);
		if (AimStarWidget)
		{
			// 将准星控件蓝图添加到视口中 
			AimStarWidget->AddToViewport();
		}
	}
}
