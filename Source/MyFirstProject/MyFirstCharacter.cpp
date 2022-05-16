// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	// #include "GameFramework/Character.h" �ʿ�
	// #include "GameFramework/CharacterMovementComponent.h" �� �ʿ�
	// �̰��Ѵ��� ĳ����BP�� �� ������Ʈ�� Use Controller Rotation Yaw�� false���ϸ� ȸ���� ��
	GetCharacterMovement()->bOrientRotationToMovement=true;
}

void AMyFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// PlayerInputComponent�� �ִ��� Ȯ��
	check(PlayerInputComponent);
	// #include "GameFramework/DefaultPawn.h" �ʿ�
	// ������ �̵�
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyFirstCharacter::MoveForward);
	// ������ �̵�
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyFirstCharacter::MoveRight);

	// ����
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AMyFirstCharacter::Attack_Melee);
}

// �յ��̵�
void AMyFirstCharacter::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false)
	{
		// #include "GameFramework/PlayerController.h" �ʿ�
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
		// �����̸� ���ݼ��� �ʱ�ȭ
		ComboAttack_Num = 0;
	}	
}

// �¿��̵�
void AMyFirstCharacter::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false)
	{
		// #include "GameFramework/PlayerController.h" �ʿ�
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
		// �����̸� ���ݼ��� �ʱ�ȭ
		ComboAttack_Num = 0;
	}
}
