// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Arrow_Base.h"
#include "Arrow_Teleport.generated.h"

/**
 * 
 */
UCLASS()
class THELASTARCHER_API AArrow_Teleport : public AArrow_Base
{
	GENERATED_BODY()
	
public:
	AArrow_Teleport();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* TraceStartPoint;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
