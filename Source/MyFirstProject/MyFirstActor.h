// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.generated.h"
// include���� �� �����δ� ���̻� ����ȵ� �������ٰ���

UCLASS()
class MYFIRSTPROJECT_API AMyFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyFirstActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* CollisionSpehere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mStaticMesh;

	// #include "Kismet/GameplayStatics.h"
	// #include "particles/ParticleSystemComponent.h"
	// �ʿ�
	UPROPERTY(EditDefaultsOnly, Category = "MyItem")
		UParticleSystem* ParticleFX;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SeepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
