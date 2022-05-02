// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"
#include "Engine.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 게임 화면 좌측 상단에 메세지
	// 근데 왠진 모르겠지만 이 코드가 언리얼 엔진을 열때 에러를 일으킬 때가 있음
	// 그럴땐 이 줄을 코멘트 처리하고 빌드한 다음 다시 프로젝트를 열면 됨
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world"));

	// 창 - 출력로그 로그창에 메세지 띄우기 워낙 다른 메세지가 많아서 Warning으로해야 잘보임 일반은 Log
	UE_LOG(LogTemp, Warning, TEXT("Hello world2"));

}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

