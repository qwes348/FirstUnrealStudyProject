// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
#include "MyFirstCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYFIRSTPROJECT_API AMyFirstCharacter : public ABasicCharacter
{
	GENERATED_BODY()

public:
	AMyFirstCharacter();

	// ī�޶� ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
	void MoveForward(float value);
	void MoveRight(float value);
};
