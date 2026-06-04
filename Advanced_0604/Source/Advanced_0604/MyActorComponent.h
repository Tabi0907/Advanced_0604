// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"

//1대 다수의 형태로 블루프린트까지 지원하는 코드를 사용함
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthDeadSignature, AController*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHealthDamagedSignature, float, NewHealth, float, MaxHealth, float, HealthChange);


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ADVANCED_0604_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UMyActorComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(BlueprintAssignable)
	FHealthDeadSignature OnHealthDead;

	UPROPERTY(BlueprintAssignable)
	FHealthDamagedSignature OnHealthDamaged;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentHealth;


	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void DamageTake(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* Causer);

};