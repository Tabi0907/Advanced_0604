// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTorchlight.generated.h"

UCLASS()
class ADVANCED_0604_API AMyTorchlight : public AActor
{
	GENERATED_BODY()


public:
	AMyTorchlight();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<TWeakObjectPtr<AActor>> Items;

	

protected:
	virtual void BeginPlay() override;

};
