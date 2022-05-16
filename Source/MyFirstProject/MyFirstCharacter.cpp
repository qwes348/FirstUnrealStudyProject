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
	// 컴포넌트에 루트에 붙이는거라고함 무슨말인지 잘 모르겠음 나중에 찾아볼것
	CameraBoom->SetupAttachment(RootComponent);
	// 지지대 설정
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// CameraBoom컴포넌트의 자식 컴포넌트로 달아주는것 같음
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// #include "GameFramework/Character.h" 필요
	// #include "GameFramework/CharacterMovementComponent.h" 도 필요
	// 이걸한다음 캐릭터BP에 폰 컴포넌트에 Use Controller Rotation Yaw를 false로하면 회전을 함
	GetCharacterMovement()->bOrientRotationToMovement=true;
}

void AMyFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// PlayerInputComponent가 있는지 확인
	check(PlayerInputComponent);
	// #include "GameFramework/DefaultPawn.h" 필요
	// 앞으로 이동
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyFirstCharacter::MoveForward);
	// 옆으로 이동
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyFirstCharacter::MoveRight);

	// 공격
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AMyFirstCharacter::Attack_Melee);
}

// 앞뒤이동
void AMyFirstCharacter::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false)
	{
		// #include "GameFramework/PlayerController.h" 필요
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
		// 움직이면 공격순서 초기화
		ComboAttack_Num = 0;
	}	
}

// 좌우이동
void AMyFirstCharacter::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false)
	{
		// #include "GameFramework/PlayerController.h" 필요
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
		// 움직이면 공격순서 초기화
		ComboAttack_Num = 0;
	}
}
