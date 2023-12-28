// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterBase.generated.h"

class URangerMonsterFSM;
class UStatesComponent;
class UNavigationInvokerComponent;
class UMonsterFSM;
class USkeletalMeshComponent;

UCLASS()
class THELASTARCHER_API AMonsterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UMonsterFSM* MonsterFsm;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStatesComponent* HP;

	UPROPERTY(EditAnywhere)
	UArrowComponent* ArrowComp;
	
	
	
};
