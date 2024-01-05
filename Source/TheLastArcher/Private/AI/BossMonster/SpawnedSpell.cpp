

#include "AI/BossMonster/SpawnedSpell.h"

#include "Player_Archer.h"
#include "Player_DamageType.h"
#include "StatesComponent.h"


ASpawnedSpell::ASpawnedSpell()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	
	// MeshComp->CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	// //MeshComp->SetupAttachment(RootComponent);
	// ConstructorHelpers::FObjectFinder<UStaticMesh>TempMesh(TEXT("/Script/Engine.StaticMesh'/Game/Resource/BossWP/Mine/Crystal_Crystal_007_low.Crystal_Crystal_007_low'"));
	// if(TempMesh.Succeeded())
	// {
	// 	MeshComp->SetStaticMesh(TempMesh.Object);
	// 	MeshComp->SetRelativeLocation(FVector(30,-30,-10));
	// 	MeshComp->SetRelativeScale3D(FVector(2.0f));
	// }
}


void ASpawnedSpell::BeginPlay()
{
	Super::BeginPlay();

	//OnComponentBeginOverlap.AddDynamic(this,&ABossSkullProjectile::OverlapBegin);
	CurrentTime += GetWorld()->GetDeltaSeconds();
	if(CurrentTime>CastTime)
	{
		if(Target != nullptr)
		{
			Target->StatesComp->TakeDamage(Target,Damag,NormalDamage,nullptr,this);
			this->Destroy();
		}
		
	}
}


void ASpawnedSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ASpawnedSpell::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
}

void ASpawnedSpell::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 부딪힌 대상이 화살인지 체크
	//if(OtherActor -> IsA<화살>())
	{
		
		
	}
}
