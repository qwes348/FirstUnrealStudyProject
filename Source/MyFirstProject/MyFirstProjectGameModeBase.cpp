// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyFirstProjectGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AMyFirstProjectGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // MyFirstProject.cs 스크립트에서 모듈추가작업 필요
    // 이거까지한다음 게임모드베이스 BP에서 위젯BP를 추가해줘야함 안하면 에러나면서 팅김
    CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidget);
    CurrentWidget -> AddToViewport();
}

