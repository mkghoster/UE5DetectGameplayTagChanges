// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorWithGameplayTags.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncPollGameplayTagChange.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayTagChanged, FGameplayTagContainer, TagContainer);

/**
 * Blueprint node to automatically poll Gameplay Tag changes on target actor.
 */
UCLASS()
class UEASYNCNODEGT_API UAsyncPollGameplayTagChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncPollGameplayTagChange* AsyncPollGameplayTagChange(
		AActor* TargetActor, float PollFrequency = 0.1f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<IGameplayTagAssetInterface> TargetGTA;

	virtual void Activate() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PollFrequency;
	
	FTimerHandle TimerHandle_Poll;
	UFUNCTION()
	virtual void Poll();
	
	UPROPERTY(BlueprintAssignable)
	FGameplayTagChanged OnGameplayTagChanged;

	UPROPERTY(BlueprintAssignable)
	FGameplayTagChanged OnTargetNotValid;

	FGameplayTagContainer GTCCache;
};
