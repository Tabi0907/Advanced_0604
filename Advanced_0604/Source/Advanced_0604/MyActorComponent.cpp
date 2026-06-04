// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100.f;
}


void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	//신호 받기!!
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UMyActorComponent::DamageTake);

}

void UMyActorComponent::DamageTake(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* Causer)
{
	float FinalDamage = FMath::Min(Damage, CurrentHealth);
	CurrentHealth -= FinalDamage;

	OnHealthDamaged.Broadcast(CurrentHealth, MaxHealth, FinalDamage);
	if (CurrentHealth == 0.f)
	{
		//신호 주기!!
		OnHealthDead.Broadcast(Instigator);
	}

}


void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("HP : %f"), CurrentHealth));
}

