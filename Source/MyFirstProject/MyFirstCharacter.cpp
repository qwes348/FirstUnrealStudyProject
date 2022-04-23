// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMyFirstCharacter::AMyFirstCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// 컴포넌트에 루트에 붙이는거라고함 무슨말인지 잘 모르겠음 나중에 찾아볼것
	CameraBoom->SetupAttachment(RootComponent);
	// 지지대 설정
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// CameraBoom컴포넌트의 자식 컴포넌트로 달아주는것 같음
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}
