// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"
#include "Engine.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���� ȭ�� ���� ��ܿ� �޼���
	// �ٵ� ���� �𸣰����� �� �ڵ尡 �𸮾� ������ ���� ������ ����ų ���� ����
	// �׷��� �� ���� �ڸ�Ʈ ó���ϰ� ������ ���� �ٽ� ������Ʈ�� ���� ��
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world"));

	// â - ��·α� �α�â�� �޼��� ���� ���� �ٸ� �޼����� ���Ƽ� Warning�����ؾ� �ߺ��� �Ϲ��� Log
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

