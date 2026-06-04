// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Advanced_0604/TestMyInterface.h"
#include "Item_Cloth.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCED_0604_API AItem_Cloth : public AItemBase, public ITestMyInterface
{
	GENERATED_BODY()
public:

	virtual void OnFireDetected_Implementation(float Temperature, FVector HitLocation) override;

protected:
	//불 파티클 넣을 공간
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* FireEffect;

};
