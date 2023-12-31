// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow_Type/Arrow_Normal.h"
#include "MonsterBase.h"
#include "Arrow_Base.h"
#include "StatesComponent.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Engine/DamageEvents.h>
#include <../../../../../../../Source/Runtime/Engine/Classes/GameFramework/DamageType.h>
#include "Player_DamageType.h"




AArrow_Normal::AArrow_Normal()
{
	Damage = 35.f;
}

void AArrow_Normal::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	/*
	if (UStatesComponent* StatesComponent = Cast<UStatesComponent>(OtherActor->GetComponentByClass(UStatesComponent::StaticClass())))
	{
		StatesComponent->TakeDamage(OtherActor, Damage, NewObject<UNormalArrow_Type>(), nullptr, this);
		
		this->Destroy();
	}
	*/

	if (OtherActor && OtherActor->IsA<AMonsterBase>()) {

		UE_LOG(LogTemp, Warning, TEXT("Hit Monster"));
		HitMonster = Cast<AMonsterBase>(OtherActor);

		Damage = 35.f;

		HitMonster->HP->TakeDamage(HitMonster, Damage, Player_DamageType, nullptr, this);

		Destroy();

	}
	

}
