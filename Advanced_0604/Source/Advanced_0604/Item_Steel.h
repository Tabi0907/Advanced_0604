// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Advanced_0604/TestMyInterface.h"
#include "Item_Steel.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCED_0604_API AItem_Steel : public AItemBase, public ITestMyInterface
{
    GENERATED_BODY()
public:
    // 이펙트를 저장할 변수 선언 (에디터에서 지정 가능하도록)
    UPROPERTY(EditAnywhere, Category = "Effects")
    class UParticleSystem* FireEffect;

    // 💡 인터페이스(ITestMyInterface)로부터 물려받은 순수 가상 함수를 여기에 선언합니다.
    // (부모 인터페이스에 적힌 함수 모양과 정확히 일치해야 합니다)
    virtual void OnFireDetected_Implementation(float Temperature, FVector HitLocation) override;
};
