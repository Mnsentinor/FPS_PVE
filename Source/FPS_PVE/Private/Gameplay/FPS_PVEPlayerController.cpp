// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/FPS_PVEPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h" 

void AFPS_PVEPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// ��ȡ��ǰ��ҿ��ƵĽ�ɫ 
	ControlledPlayer = UGameplayStatics::GetPlayerCharacter(this, 0);
	
	// ����׼�ǿؼ���ͼ 
	// ����ʱ��̬���� Widget Blueprint
	AimStar = LoadClass<UUserWidget>(nullptr, TEXT("/Game/UI/PlayerGameUI.PlayerGameUI_C"));
	//AimStar = StaticLoadClass(UUserWidget::StaticClass(), nullptr, TEXT("WidgetBlueprint'/Game/UI/PlayerGameUI.PlayerGameUI_C'"));

	if (AimStar)
	{
		UUserWidget* AimStarWidget = CreateWidget<UUserWidget>(GetWorld(), AimStar);
		if (AimStarWidget)
		{
			// ��׼�ǿؼ���ͼ��ӵ��ӿ��� 
			AimStarWidget->AddToViewport();
		}
	}
}
