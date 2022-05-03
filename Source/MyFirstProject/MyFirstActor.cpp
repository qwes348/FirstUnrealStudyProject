// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"
#include "Engine.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BasicCharacter.h"
#include "MyFirstCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "particles/ParticleSystemComponent.h"

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

	// Obj��� �̸����� ����ƽ �޽� ������Ʈ�� �ڽ����� �޾���
	mStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obj"));

	// �߽���� => �̰� ���ϸ� ����ƽ�޽� �����̴´�� �ݶ��̴��� �ȵ����
	// �ٵ� �̰��ϰ����� �߽��� �ȸ¾Ƽ� �������Ʈ�� �ٽø���ϱ� ����
	RootComponent = mStaticMesh;

	// CollisionSphere��� �̸����� �ݶ��̴� ������Ʈ�� �޾���
	CollisionSpehere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSpehere->InitSphereRadius(100.0f);
	CollisionSpehere->SetupAttachment(RootComponent);		

	// �浹������ ��������Ʈ �߰�
	CollisionSpehere->OnComponentBeginOverlap.AddDynamic(this, &AMyFirstActor::OnOverlapBegin);

	/*
		#include "Kismet/GameplayStatics.h"
		#include "particles/ParticleSystemComponent.h"
		�ʿ�
	*/
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
	ParticleFX = ParticleAsset.Object;
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

// �浹�� ȣ��
void AMyFirstActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �ε����� ĳ���� Ŭ�������� Ȯ��
	if(OtherActor->IsA(AMyFirstCharacter::StaticClass()))
	{
		// ��ƼŬ ��ȯ
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX, GetActorLocation());
		// ������Ʈ ����
		Destroy();
	}
}

