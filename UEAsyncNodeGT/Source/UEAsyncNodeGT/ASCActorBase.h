// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "ASCActorBase.generated.h"

UCLASS()
class UEASYNCNODEGT_API AASCActorBase : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AASCActorBase();

	// Implement IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	class UAbilitySystemComponent* AbilitySystemComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
