// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter.h"

// Sets default values
ABasicCharacter::ABasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicCharacter::Attack_Melee()
{
	if(ComboAttack_Num < 3)
	{
		int tmp_Num = rand() % 3 + 1;

		// Attack_(num)섹션을 랜덤으로 뽑아서 1,2,3중에 랜덤으로 출력함
		FString PlaySection = "Attack_" + FString::FromInt(tmp_Num);

		PlayAnimMontage(AttackCombo_AnimMt, 1.f, FName(*PlaySection));

		ComboAttack_Num++;

		UE_LOG(LogTemp, Warning, TEXT("Combo : %d"), ComboAttack_Num);

		isDuringAttack = true;
	}
	else
	{
		// 피니쉬어택
		PlayAnimMontage(LastAttack_Anims, 1.f);
		ComboAttack_Num = 0;
	}


	// 1.7초후에 Attack_Melee_End를 호출
	// 여기 초를 더 늘려야함 피니쉬어택때문에
	FTimerHandle TH_Attack_End;
	GetWorldTimerManager().SetTimer(TH_Attack_End, this, &ABasicCharacter::Attack_Melee_End, 1.7f, false);
	
}

void ABasicCharacter::Attack_Melee_End()
{
	isDuringAttack = false;
	ComboAttack_Num = 0;
}

