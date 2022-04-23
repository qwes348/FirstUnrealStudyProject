// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMyFirstCharacter::AMyFirstCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// ������Ʈ�� ��Ʈ�� ���̴°Ŷ���� ���������� �� �𸣰��� ���߿� ã�ƺ���
	CameraBoom->SetupAttachment(RootComponent);
	// ������ ����
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// CameraBoom������Ʈ�� �ڽ� ������Ʈ�� �޾��ִ°� ����
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}
