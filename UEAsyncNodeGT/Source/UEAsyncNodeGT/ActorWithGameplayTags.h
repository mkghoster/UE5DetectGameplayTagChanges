// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "ActorWithGameplayTags.generated.h"

UCLASS()
class UEASYNCNODEGT_API AActorWithGameplayTags : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer OwnedGameplayTags;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
};
