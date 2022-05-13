// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicCharacter.generated.h"

UCLASS()
class MYFIRSTPROJECT_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack_Melee();
	void Attack_Melee_End();

	// 몽타주 에셋을 디테일뷰에서 집어넣을수있게 추가
	// 카테고리를 지정했기때문에 폰 카테고리 아래로 들어감
	UPROPERTY(EditDefaultsOnly, Category=Pawn)
	UAnimMontage* Attack_Melee_Anim01;

	UPROPERTY(EditDefaultsOnly, Category=Pawn)
	UAnimMontage* Attack_Melee_Anim02;

	UPROPERTY(EditDefaultsOnly, Category=Pawn)
	UAnimMontage* Attack_Melee_Anim03;

	bool isDuringAttack;

	int ComboAttack_Num;
};
