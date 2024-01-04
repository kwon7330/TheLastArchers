


#include "AI/BossMonster/MonsterBoss.h"

#include "StaticMeshAttributes.h"
#include "AI/BossMonster/MonsterBossFSM.h"
#include "Components/SphereComponent.h"


AMonsterBoss::AMonsterBoss()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	BossFsm = CreateDefaultSubobject<UMonsterBossFSM>("BossFSM");
	
//=======~================================================================================================================================
	// Mesh를 가져온다.
	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshTemp(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/BossMonster/Model/BossMonster.BossMonster_C'"));
	if(MeshTemp.Succeeded())
	{
		GetMesh()->SetRelativeLocationAndRotation(FVector(0,0,-90),FRotator(0,0,-90));
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetMesh()->SetRelativeScale3D(FVector(100,100,100));
	}
	
//=======~================================================================================================================================
	// 돌이 소환 되는 위치를 정한다.
	SpawnStone = CreateDefaultSubobject<USkeletalMeshComponent>("SpawnStone");
	SpawnStone -> SetupAttachment(GetMesh(),"SpawnPoint");
	SpawnStone -> SetCollisionEnabled(ECollisionEnabled::NoCollision);
//=======~================================================================================================================================

	// 머리 쪽에 1페이지 타격이 가능한 컴퍼넌트를 만든다.
	DamagePoint = CreateDefaultSubobject<USphereComponent>("DamagePoint");
	DamagePoint -> SetupAttachment(GetMesh(),"DamageSocket");
	//(X=0.000000,Y=0.500000,Z=1.000000)
	DamagePoint -> SetRelativeLocation(FVector(0,0.5f,1.0f));
	DamagePoint -> SetRelativeScale3D(FVector(0.04f));
}


void AMonsterBoss::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMonsterBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMonsterBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

