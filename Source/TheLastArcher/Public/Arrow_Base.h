// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow_Base.generated.h"

UCLASS()
class THELASTARCHER_API AArrow_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrow_Base();

	float ArrowSpeed = 3000.f;

	bool bIsShotArrow = false;

	FVector ArrowDirection = GetActorForwardVector();

	// 화살 날아가는 방향
	FVector ArrowGoingDirection;

	// 플레이어 저장할 변수
	class APlayer_Archer* Player_Archer;

	// 부딪힌 몬스터 저장할 변수
	class AMonsterBase* HitMonster;

	class UPlayer_DamageType* Player_DamageType;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


public:
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* ArrowCollisionComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ArrowMeshComp;


	

	
};
