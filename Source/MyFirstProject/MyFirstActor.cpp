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

	// 게임 화면 좌측 상단에 메세지
	// 근데 왠진 모르겠지만 이 코드가 언리얼 엔진을 열때 에러를 일으킬 때가 있음
	// 그럴땐 이 줄을 코멘트 처리하고 빌드한 다음 다시 프로젝트를 열면 됨
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world"));

	// 창 - 출력로그 로그창에 메세지 띄우기 워낙 다른 메세지가 많아서 Warning으로해야 잘보임 일반은 Log
	UE_LOG(LogTemp, Warning, TEXT("Hello world2"));

	// Obj라는 이름으로 스태틱 메쉬 컴포넌트를 자식으로 달아줌
	mStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obj"));

	// 중심잡기 => 이거 안하면 스태틱메쉬 움직이는대로 콜라이더가 안따라옴
	// 근데 이거하고나서도 중심이 안맞아서 블루프린트를 다시만드니까 됐음
	RootComponent = mStaticMesh;

	// CollisionSphere라는 이름으로 콜라이더 컴포넌트를 달아줌
	CollisionSpehere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSpehere->InitSphereRadius(100.0f);
	CollisionSpehere->SetupAttachment(RootComponent);		

	// 충돌됐을때 델리게이트 추가
	CollisionSpehere->OnComponentBeginOverlap.AddDynamic(this, &AMyFirstActor::OnOverlapBegin);

	/*
		#include "Kismet/GameplayStatics.h"
		#include "particles/ParticleSystemComponent.h"
		필요
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

// 충돌시 호출
void AMyFirstActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 부딪힌게 캐릭터 클래스인지 확인
	if(OtherActor->IsA(AMyFirstCharacter::StaticClass()))
	{
		// 파티클 소환
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX, GetActorLocation());
		// 오브젝트 삭제
		Destroy();
	}
}

