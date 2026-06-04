// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTorchlight.h"
#include "Kismet/KismetSystemLibrary.h"
// 💡 인터페이스를 안전하게 사용하기 위해 경로를 맞춰 헤더를 포함합니다.
#include "TestMyInterface.h" 

// Sets default values
AMyTorchlight::AMyTorchlight()
{
	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyTorchlight::BeginPlay()
{
	Super::BeginPlay();

	for (const TWeakObjectPtr<AActor>& Item : Items)
	{
		if (UKismetSystemLibrary::DoesImplementInterface(Item.Get(), UTestMyInterface::StaticClass()))
		{
			ITestMyInterface::Execute_OnFireDetected(Item.Get(), 100.f, FVector::ZeroVector);
		}
	}
}

// Called every frame
void AMyTorchlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}