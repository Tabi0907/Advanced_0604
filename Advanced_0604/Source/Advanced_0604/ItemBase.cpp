// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Kismet/GameplayStatics.h"
#include "Advanced_0604/MyActorComponent.h"
#include "GameFramework/Character.h"
// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerCharacter)
	{
		UMyActorComponent* HealthComp = PlayerCharacter->FindComponentByClass<UMyActorComponent>();

		if (HealthComp)
		{
			// 플레이어가 죽을 때 신호를 받도록 등록
			HealthComp->OnHealthDead.AddDynamic(this, &AItemBase::PlayerDeathReceive);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("플레이어 캐릭터에 MyActorComponent가 없습니다!"));
		}
	}
}

// 💡 파일 맨 아래나 편한 곳에 함수 구현부를 통째로 추가합니다.
void AItemBase::PlayerDeathReceive(AController* InstigatorController)
{
	UE_LOG(LogTemp, Warning, TEXT("플레이어 캐릭터가 사망했습니다!"));

	// 신호를 받으면 맵에 배치된 이 액터 자신을 파괴
	Destroy();
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

