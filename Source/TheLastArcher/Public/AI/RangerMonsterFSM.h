// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/MonsterFSM.h"
#include "RangerMonsterFSM.generated.h"

/**
 * 
 */
UCLASS()
class THELASTARCHER_API URangerMonsterFSM : public UMonsterFSM
{
	GENERATED_BODY()

	URangerMonsterFSM();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void TickAttack() override;
	
	
	void SpawnArrow();

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AMonsterArrowActor> ArrowClass;

	
};